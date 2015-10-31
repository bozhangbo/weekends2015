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

// PainterView.h : interface of the CPainterView class
//

#pragma once

#include <vector>
#include <memory>

enum ToolType
{
	ToolTypeLine,
	ToolTypeRectangle,

};

class CLine;
class CRectangle;

class CPainterView : public CView
{
protected: // create from serialization only
	CPainterView();
	DECLARE_DYNCREATE(CPainterView)

// Attributes
public:
	CPainterDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	void Draw(Gdiplus::Graphics& graphics);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
 	std::shared_ptr<CLine> _temp_line;
	std::shared_ptr<CRectangle> _temp_rect;

	ToolType _tool;

public:
	afx_msg void OnButtonLine();
	afx_msg void OnUpdateButtonLine(CCmdUI *pCmdUI);
	afx_msg void OnButtonRectangle();
	afx_msg void OnUpdateButtonRectangle(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in PainterView.cpp
inline CPainterDoc* CPainterView::GetDocument() const
   { return reinterpret_cast<CPainterDoc*>(m_pDocument); }
#endif

