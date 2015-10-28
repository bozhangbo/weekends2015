// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// PainterView.cpp : implementation of the CPainterView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Painter.h"
#endif

#include "PainterDoc.h"
#include "PainterView.h"
#include <Gdiplus.h>

#include "Rectangle.h"

using namespace std;
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPainterView

IMPLEMENT_DYNCREATE(CPainterView, CView)

BEGIN_MESSAGE_MAP(CPainterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPainterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOVE()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_RECTANGLE, &CPainterView::OnRectangle)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CPainterView::OnUpdateRectangle)
	ON_COMMAND(ID_LINE, &CPainterView::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CPainterView::OnUpdateLine)
END_MESSAGE_MAP()

// CPainterView construction/destruction

CPainterView::CPainterView()
{
	_paintingtype = Line;
	// TODO: add construction code here

}

CPainterView::~CPainterView()
{
}

BOOL CPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPainterView drawing

void CPainterView::OnDraw(CDC* pDC)
{
	Gdiplus::Graphics graphics(pDC->m_hDC);

	CRect rect;
	GetClientRect(rect);

	Gdiplus::Bitmap bitmap(rect.Width(), rect.Height(), &graphics);
	Gdiplus::Graphics buffer_graphics(&bitmap);

	Draw(buffer_graphics);
	graphics.DrawImage(&bitmap, rect.left, rect.top, rect.right, rect.bottom);
}

void CPainterView::Draw(Gdiplus::Graphics& graphics)
{
	CPainterDoc* doc = GetDocument();
	ASSERT_VALID(doc);
	if (!doc)
		return;

	CRect rect;
	GetClientRect(rect);

	SolidBrush BKbrush(Gdiplus::Color::White);
	graphics.FillRectangle(&BKbrush, 0, 0, rect.Width(), rect.Height());

	switch (_paintingtype)
	{
	case Line:
	{

				 auto& lines = doc->GetLines();

				 Pen pen(Color::Red);
				 for (auto iter = lines.begin(); iter != lines.end(); ++iter)
				 {
					 (*iter)->Draw(graphics);
				 }

				 if (_temp_line)
				 {
					 _temp_line->Draw(graphics);
				 }
				 break;
	}
	case PaintingRectangle:
	{
							  auto& rectangles = doc->GetRectangle();
							  Pen pen(Color::Green);
							  for (auto iter = rectangles.begin(); iter != rectangles.end(); ++iter)
							  {
								  (*iter)->Draw(graphics);
							  }
							  if (_temp_rectanle)
							  {
								  _temp_rectanle->Draw(graphics);

							  }
							  //graphics.DrawRectangle(&pen, 10,10,100,100);
							  break;
	}
	default:
		break;
	}
}


// CPainterView printing


void CPainterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPainterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPainterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPainterView diagnostics

#ifdef _DEBUG
void CPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPainterDoc* CPainterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPainterDoc)));
	return (CPainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CPainterView message handlers


void CPainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	switch (_paintingtype)
	{
	case Line:
		_temp_line = shared_ptr<CLine>(new CLine);

		_temp_line->SetPoint1(Point(point.x, point.y));
		_temp_line->SetPoint2(Point(point.x, point.y));

		break;
	case PaintingRectangle:
		_temp_rectanle = shared_ptr<CRectangle>(new CRectangle);

		_temp_rectanle->SetPoint1(Point(point.x, point.y));
		_temp_rectanle->SetPoint2(Point(point.x, point.y));

		break;
	default:
		break;
	}

	Invalidate(FALSE);
	UpdateWindow();

	CView::OnLButtonDown(nFlags, point);
}


void CPainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	auto doc = GetDocument();
	if (doc == nullptr)
		return;
	switch (_paintingtype)
	{case Line:
		if (_temp_line)
		{
			doc->AddLine(_temp_line);
			_temp_line.reset();
		}
		break;
	case PaintingRectangle:
		if (_temp_rectanle)
		{
		doc->AddRectangle(_temp_rectanle);
		_temp_rectanle.reset();
		}
		break;
	default:
		break;
	}
	

	CView::OnLButtonUp(nFlags, point);
}


void CPainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON && (_temp_line||_temp_rectanle))
	{
		switch (_paintingtype)
		{
		case Line:		
			_temp_line->SetPoint2(Point(point.x, point.y)); 
			break;
		case PaintingRectangle:
			_temp_rectanle->SetPoint2(Point(point.x, point.y)); 
			break;
		default:
			break;
		}

	}
	Invalidate(FALSE);
	UpdateWindow();

	CView::OnMouseMove(nFlags, point);
}


void CPainterView::OnRectangle()
{
	_paintingtype = PaintingRectangle;
	// TODO: Add your command handler code here
}


void CPainterView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck((_paintingtype==PaintingRectangle) ? 1 : 0);
	// TODO: Add your command update UI handler code here
}


void CPainterView::OnLine()
{
	_paintingtype = Line;
	// TODO: Add your command handler code here
}


void CPainterView::OnUpdateLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(_paintingtype == Line ? 1 : 0);
	// TODO: Add your command update UI handler code here
}
