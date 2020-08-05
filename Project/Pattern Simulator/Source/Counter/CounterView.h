
// CounterView.h : interface of the CCounterView class
#include "CounterDoc.h"
#include "Values.h"
#pragma once


#define HEIGHT 40
#define WIDTH 40
#define X_OFFSET 50
#define Y_OFFSET 10

#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define CUSTOM 5


class CCounterView : public CView
{
protected: // create from serialization only
	CCounterView();
	DECLARE_DYNCREATE(CCounterView)
	CWinThread *pThread;


// Attributes
	int m_iYoffset;
	int m_iXoffset;
	int m_iWidth;
	int m_iHeight;
	int m_iColumns;
	int m_iRow;
	int dx = 0;
	int dy = 0;
	int x = 0;
	int y = 0;

public:
	CCounterDoc* GetDocument() const;
	CArray<CPoint, CPoint>m_PointArray;
	CArray<CValues, CValues>m_Spiral;
	CArray<CValues, CValues>m_Cdamped;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCounterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg
		void OnGridsize4(CDC * pDC);
	void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	long m_Counter;
	long m_MatrixSize;
	long maxPoints;
	long points;
	long m_dRadius;
	long condition;
	afx_msg void OnThreadStart();
	afx_msg void OnThreadPause();
	afx_msg void OnThreadResume();
	void DrawGrid(CDC *pDC);
;
	
	
	afx_msg void OnPatternDefaultsetting();
	afx_msg void OnSelectPattern();
	afx_msg void OnViewToolbarsanddockingwindows();
};

#ifndef _DEBUG  // debug version in CounterView.cpp
inline CCounterDoc* CCounterView::GetDocument() const
   { return reinterpret_cast<CCounterDoc*>(m_pDocument); }
#endif

