//1번
문제 1번의 경우 CChildView::OnPaint() 함수 내에서

CRect 객체를 생성하고 dc.Rectangle() 함수에 객체를 넣어주면 됩니다.
//2번
문제 2번의 경우 CChildView::OnPaint() 함수 내에서 CRect 객체를 선언하고 GetClientRect(&rect)를 통해 윈도우 크기를 객체에 정의한다.다음 
dc.Ellipse() 함수내에 rect.Width(), rect.Height()를 통해 접근한다.

//3번
우선 CList<CPoin, POINT&> clist를 전역으로 선언한다.

CChildView::OnRButtonDown(UINT nFlags, CPoint point) 메세지 처리기 안에

CClientDC를 설정하고 버튼이 눌릴때 마다 list.AddTail(point)로 해당 점의 좌표를 리스트에 추가한 후, 화면에

dc.Ellipse() 함수를 통해 뿌려준다.->Invalidate(FALSE);



다음 CChildView::OnPaint() 함수에서 저장된 정보를 불러와 실행하면된다.

POSITION pos = list.GetHeadPosition();

while (pos) {

    CPoint pt = list.GetNext(pos);

    dc.Ellipse(pt.x - 20, pt.y - 20, pt.x + 20, pt.y + 20);

}
//4번
CArray<CPoint, POINT&> carray; 를 전역으로 생성하고, CChildView::ChildView() 생성자에 array의 사이즈를 선언한다.리스트와 다르게 배열은 초기 사이즈를 설정해야하기 때문이다.

그 다음 CChildView::OnRButtonDown(UINT nFlags, CPoint point) 메세지 처리기 안에 포인트 좌표를 array에 추가한다.->Invalidate(FALSE);

CChildView::OnPaint() 함수에서 array.GetSize() 만큼 내용을 화면에 출력하면 된다.

//5번
CChildView::OnLButtonDown(UINT nFlags, CPoint point) 함수에선 노란 사각형을 찍으면 된다.

CClientDC dc(this)를 생성하고, dc.FillSolidRect(&rect, (RGB(255, 255, 0)) 함수를 사용하여 생성한 rect 객체에 대해 해당 RGB 값으로 채우면 된다.



    CChildView::OnRButtonDown(UINT nFlags, CPoint point) 함수에선 해당 좌표를 찍으면 된다.

    CString str = _T(" "); 객체를 생성하고 Format() 함수를 사용하여 해당 좌표 값을 채운다.그다음 dc.SetBkMode(TRANSPARENT); 함수를 사용해 투명 모드를 설정한다.

    //6번
    우선 CList<CPoint, POINT&> Llist, Rlist; 를 전역으로 설정한다.

    CChildView::CChildView() 생성자에 CMetaFileDC을 설정하고 CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    해당 내용을 리스트에 추가한다.->Invalidate(false); 사용 다음 CChildView::OnPaint() 함수에서 해당 리스트의 정보를 실행하면된다.

    //7번
    CList<CRect, RECT&> Clist; 를 전역으로 설정하고 CChildView::CChildView() 생성자에 CMetaFileDC을 만든다.

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    메세지 처리기에 대해서 CRect 객체를 생성하고, list에 해당 내용을 추가한다.->Invalidate(false);

CChildView::OnPaint() 함수에서 해당 list의 정보를 출력한다.

//8번
아직 메타파일 저장법에 대해 완벽한 숙지가 된거 같지 않습니다.하지만 메타 파일에 대한 파일명 지정은 CMetaFileDC::CreateEnhanced() 함수 두 번째 인자를 이용합니다.

//9번
CChildView::OnPaint() 함수 안에 이중 for문을 이용하여 dc.SetPixelV(x, y, RGB(x, y, 0); 으로 해당 화면 값을 채워 넣는다.

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    함수 내에서 CClientDC dc(this)를 선언하고, COLORREF color = dc.GetPixel(point); 로 RGB값을 사용한다.

    CString 객체를 선언하고 Format() 함수를 이용하여 GetRValue(), GetGValue(), GetBValue() 함수로 RGB 값을 대입하여 출력한다.

    //10번
    
//11번우선 GetClientRect(&rect) 함수로 해당 윈도우의 사각형 값을 가져옵니다.

    int centerX, centerY 에 rect.Width() / 2, rect.Height() / 2 값을 저장합니다.dc.MoveTo(), dc.LineTo() 함수를 이용하여 윈도우에 + 표시를 해줍니다.

    CArray<POINT, POINT&> carray; 를 선언하고 double PI = 3.14159265; 로 설정합니다.

    for문을 사용하여 POINT pt 객체에 x, y값을 cos() 연산을 진행하고 array에 추가합니다.

    마지막으로 dc.Polyline(array.GetData(), array.GetSize()); 를 통해 다각선을 그려주면 완성됩니다.

    //12번
    11번 문제처럼 GetClientRect(&rect)와 MoveTo(), LineTo() 함수를 사용하여, POINT points[] = { } 로 dc.Polyine() 이용해 마름모를 그려줍니다.

    dc.SetMapMode(MM_LOMETRIC);

CSize size = dc.GetWindowExt();

CRect rect1(CPoint(0, 0), size);

rect1.bottom = -100;



CPen pen(PS_SOLID, 5, RGB(0, 0, 0));

dc.SelectObject(&pen);

dc.Rectangle(rect1);

dc.TextOutW(5, -40, _T("0"));

for (int i = 100; i < rect1.right; i += 100) {

    dc.MoveTo(i, 0);

    dc.LineTo(i, -60);

    if (i % 100 == 0) {
        CString str;

        str.Format(_T("%d"), i / 100);

        CRect rect1(i - 100, -40, i - 5, -100);

        dc.DrawText(str, str.GetLength(), rect1, DT_RIGHT | DT_TOP | DT_SINGLELINE);

    }

}

dc.SelectStockObject(BLACK_PEN);



for (int i = 10; i < rect.right; i += 10) {

    if (i % 50 == 0) {

        dc.MoveTo(i, 0);

        dc.LineTo(i, -40);

    }

    else if (i % 10 == 0) {

        dc.MoveTo(i, 0);

        dc.LineTo(i, -20);

    }

}
//13번
CFont::CreatePointFont() 함수에서 인자를 _T("맑은 고딕") 식으로 설정하면 출력됩니다.

//14본
CFont::CreatePointFont() 함수에서 인자를 FW_BOLD 로 하면 볼드체가 출력됩니다.나머지 경우 TRUE / FALSE를 통해 이탤릭과 밑줄 폰트를 출력할 수 있습니다.

//15번
CFont::CreatePointFontW(-::MulDiv(10, GetDeviceCaps(dc.m_hDC, LOGPIXELSY), 72)-- -

    10, 12, 14를 통해 해당 글자의 크기를 조절할 수 있습니다.

    //16번
    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)
    //17번
    마찬가지로

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    메세지 처리기에 대해 CDC::SetMapMode() 함수를 통하여 매핑 모드를 전환하면 된다.->Invalidate(false) 주의

    //18번
    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    메세지 처리기에 CPen 클래스 생성자에서 첫번째 인수를 변경하면 동작한다.->Invalidate(false) 주의

    //19번
    GetClientRect(&rect); 를 사용하여 윈도우 사각형을 가져온다.

    CPen pen(PS_NULL, 1, RGB(0, 0, 0); 으로 NULL 펜을 사용하여 외각선을 출력시키지 않는다.

        CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0); 을 사용하여 사각형을 그린다.

    //20번
            CChildView::PreCreateWindow(CREATESTRUCT & cs) 함수 내에

            CBitmap bitmap;

bitmap.LoadBitmapW(IDB_BITMAP1);

HBRUSH brush = CreatePatternBrush(bitmap);

사용하여 AfxRegisterWndClass() 인자에 brush 객체를 넣어준다.
//21번
dc.SelectStockObject() 함수를 사용하여 ANSI_FIXED_FONT / ANSI_VAR_FONT를 사용하여 TextOutW()함수를 통해 출력한다.

//22번
CChildView::OnLButtonDown(UINT nFlags, CPoint point) 함수에

CClientDC를 설정하고 CBitmap 객체를 선언하고 BITMAP bmpinfo 객체도 선언한다.

dc.StretchBlt(10, 10, bmpinfo.bmWidth * 10, bmpinfo.Height * 10, &mem, 0, 0, bmpinfo.bmWidth, bmpinfo.bm.Height, SRCCOPY); 를 통해 비트맵 객체를 늘린다.


//23번
CChildView::OnLButtonDown(UINT nFlags, CPoint point) 함수에

dc.StretchBlt(10 + bmpinfo.bmWidth - 1, bmpinfo.bmHeight - 1, -bmpinfo.bmWidth, -bmpinfo.Height, &mem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY); 안의 인수를 수정하여 비트맵을 거꾸로 출력한다.

//24번
겹친 지역에 대해서 CBrush brush(RGB(255, 0, 0)); 객체를 선언하고 dc.FillRgn(&rgn1, &brush); 를 통해 채색한다.

