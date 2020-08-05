// TestThread.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "TestThread.h"
#include  "CounterView.h"
#include "CounterDoc.h"
#include "Values.h"




// CTestThread

IMPLEMENT_DYNCREATE(CTestThread, CWinThread)

CTestThread::CTestThread()
{
}

CTestThread::~CTestThread()
{
}

BOOL CTestThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CTestThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CTestThread, CWinThread)
END_MESSAGE_MAP()


// CTestThread message handlers


UINT CTestThread::RunThreadFunction(LPVOID param)
{
	CCounterView *pCounterView = (CCounterView *)param;
	int local = pCounterView->condition;

	CPoint Point;
	CValues cdamp;


	if (local == 1)
	{
		
		while (1)
		{
			CPoint Point;
			Point.x = rand() / 500 + 300;
			Point.y = rand() / 500 + 300;
			pCounterView->m_PointArray.Add(Point);
			Sleep(100);
			pCounterView->Invalidate();
		}

	}

	else if (local == 2)
	{
		CValues values;
        while (values.m_dTheta <= 500)
		{
			values.m_dTheta += values.m_dDelta;
			values.m_dRadius = values.m_dTheta;
			values.m_dX = (values.m_dRadius* cos(values.m_dRadius / 10 * 3.14)) + values.m_dX;
			values.m_dY = (values.m_dRadius* sin(values.m_dRadius / 10 * 3.14)) + values.m_dY;
			pCounterView->m_Spiral.Add(values);
			pCounterView->Invalidate();
			Sleep(100);
		}

	}

	else if (local == 3)
	{
	    while (1)
		{
			int t = 0;
			t = cdamp.m_dAmplitude;
			for (int i = 1; i < cdamp.m_dAmplitude; i++)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / t;
				t--;
				cdamp.m_dY1 -= 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			t = 1;
			for (int j = cdamp.m_dAmplitude; j > 0; j--)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / t;
				t++;
				cdamp.m_dY1 += 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			t = cdamp.m_dAmplitude;
			for (int i = 1; i < cdamp.m_dAmplitude; i++)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / t;
				t--;
				cdamp.m_dY1 += 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			t = 1;
			for (int j = cdamp.m_dAmplitude; j > 0; j--)
			{
				cdamp.m_dX1 += cdamp.m_dPeriod / t;
				t++;
				cdamp.m_dY1 -= 1;
				pCounterView->m_Cdamped.Add(cdamp);
			}
			pCounterView->m_Cdamped.Add(cdamp);
			cdamp.m_dAmplitude -= 9;
			pCounterView->Invalidate();
			Sleep(500);
		}

	}
	return 0;
}





