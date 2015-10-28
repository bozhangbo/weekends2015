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

// PainterDoc.cpp : implementation of the CPainterDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Painter.h"
#endif

#include "PainterDoc.h"

#include <propkey.h>
#include <memory>
#include "line.h"
#include <gdiplus.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace Gdiplus;

// CPainterDoc

IMPLEMENT_DYNCREATE(CPainterDoc, CDocument)

BEGIN_MESSAGE_MAP(CPainterDoc, CDocument)
END_MESSAGE_MAP()


// CPainterDoc construction/destruction

CPainterDoc::CPainterDoc()
{
	// TODO: add one-time construction code here

}

CPainterDoc::~CPainterDoc()
{
}

BOOL CPainterDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


// CPainterDoc serialization

void CPainterDoc::Serialize(CArchive& ar)
{
	ar << static_cast<size_t>(_lines.size());
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		for (auto line = _lines.begin(); line != _lines.end(); ++line)
		{
			ar << (*line)->GetPoint1().X << (*line)->GetPoint1().Y
				<< (*line)->GetPoint2().X << (*line)->GetPoint2().Y;
		}
	}
	else
	{
		// TODO: add loading code here
		_lines.clear();

		size_t size;
		ar >> size;

		Point point1, point2;
		for (size_t i = 0; i < size; ++i)
		{
			ar >> point1.X >> point1.Y >> point2.X >> point2.Y;
			shared_ptr<CLine> line(new CLine);
			line->SetPoint1(point1);
			line->SetPoint2(point2);

			_lines.push_back(line);
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CPainterDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CPainterDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CPainterDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CPainterDoc diagnostics

#ifdef _DEBUG
void CPainterDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPainterDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

const vector<shared_ptr<CLine>>& CPainterDoc::GetLines() const
{
	return _lines;
}

void CPainterDoc::AddLine(shared_ptr<CLine> line)
{
	_lines.push_back(line);
}

const std::vector<std::shared_ptr<CRectangle>>& CPainterDoc::GetRectangle() const
{
	return _rectangles;
}

void CPainterDoc::AddRectangle(std::shared_ptr<CRectangle> rectangle)
{
	_rectangles.push_back(rectangle);
}


#endif //_DEBUG


// CPainterDoc commands
