//1��
���� 1���� ��� CChildView::OnPaint() �Լ� ������

CRect ��ü�� �����ϰ� dc.Rectangle() �Լ��� ��ü�� �־��ָ� �˴ϴ�.
//2��
���� 2���� ��� CChildView::OnPaint() �Լ� ������ CRect ��ü�� �����ϰ� GetClientRect(&rect)�� ���� ������ ũ�⸦ ��ü�� �����Ѵ�.���� 
dc.Ellipse() �Լ����� rect.Width(), rect.Height()�� ���� �����Ѵ�.

//3��
�켱 CList<CPoin, POINT&> clist�� �������� �����Ѵ�.

CChildView::OnRButtonDown(UINT nFlags, CPoint point) �޼��� ó���� �ȿ�

CClientDC�� �����ϰ� ��ư�� ������ ���� list.AddTail(point)�� �ش� ���� ��ǥ�� ����Ʈ�� �߰��� ��, ȭ�鿡

dc.Ellipse() �Լ��� ���� �ѷ��ش�.->Invalidate(FALSE);



���� CChildView::OnPaint() �Լ����� ����� ������ �ҷ��� �����ϸ�ȴ�.

POSITION pos = list.GetHeadPosition();

while (pos) {

    CPoint pt = list.GetNext(pos);

    dc.Ellipse(pt.x - 20, pt.y - 20, pt.x + 20, pt.y + 20);

}
//4��
CArray<CPoint, POINT&> carray; �� �������� �����ϰ�, CChildView::ChildView() �����ڿ� array�� ����� �����Ѵ�.����Ʈ�� �ٸ��� �迭�� �ʱ� ����� �����ؾ��ϱ� �����̴�.

�� ���� CChildView::OnRButtonDown(UINT nFlags, CPoint point) �޼��� ó���� �ȿ� ����Ʈ ��ǥ�� array�� �߰��Ѵ�.->Invalidate(FALSE);

CChildView::OnPaint() �Լ����� array.GetSize() ��ŭ ������ ȭ�鿡 ����ϸ� �ȴ�.

//5��
CChildView::OnLButtonDown(UINT nFlags, CPoint point) �Լ����� ��� �簢���� ������ �ȴ�.

CClientDC dc(this)�� �����ϰ�, dc.FillSolidRect(&rect, (RGB(255, 255, 0)) �Լ��� ����Ͽ� ������ rect ��ü�� ���� �ش� RGB ������ ä��� �ȴ�.



    CChildView::OnRButtonDown(UINT nFlags, CPoint point) �Լ����� �ش� ��ǥ�� ������ �ȴ�.

    CString str = _T(" "); ��ü�� �����ϰ� Format() �Լ��� ����Ͽ� �ش� ��ǥ ���� ä���.�״��� dc.SetBkMode(TRANSPARENT); �Լ��� ����� ���� ��带 �����Ѵ�.

    //6��
    �켱 CList<CPoint, POINT&> Llist, Rlist; �� �������� �����Ѵ�.

    CChildView::CChildView() �����ڿ� CMetaFileDC�� �����ϰ� CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    �ش� ������ ����Ʈ�� �߰��Ѵ�.->Invalidate(false); ��� ���� CChildView::OnPaint() �Լ����� �ش� ����Ʈ�� ������ �����ϸ�ȴ�.

    //7��
    CList<CRect, RECT&> Clist; �� �������� �����ϰ� CChildView::CChildView() �����ڿ� CMetaFileDC�� �����.

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    �޼��� ó���⿡ ���ؼ� CRect ��ü�� �����ϰ�, list�� �ش� ������ �߰��Ѵ�.->Invalidate(false);

CChildView::OnPaint() �Լ����� �ش� list�� ������ ����Ѵ�.

//8��
���� ��Ÿ���� ������� ���� �Ϻ��� ������ �Ȱ� ���� �ʽ��ϴ�.������ ��Ÿ ���Ͽ� ���� ���ϸ� ������ CMetaFileDC::CreateEnhanced() �Լ� �� ��° ���ڸ� �̿��մϴ�.

//9��
CChildView::OnPaint() �Լ� �ȿ� ���� for���� �̿��Ͽ� dc.SetPixelV(x, y, RGB(x, y, 0); ���� �ش� ȭ�� ���� ä�� �ִ´�.

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    �Լ� ������ CClientDC dc(this)�� �����ϰ�, COLORREF color = dc.GetPixel(point); �� RGB���� ����Ѵ�.

    CString ��ü�� �����ϰ� Format() �Լ��� �̿��Ͽ� GetRValue(), GetGValue(), GetBValue() �Լ��� RGB ���� �����Ͽ� ����Ѵ�.

    //10��
    
//11���켱 GetClientRect(&rect) �Լ��� �ش� �������� �簢�� ���� �����ɴϴ�.

    int centerX, centerY �� rect.Width() / 2, rect.Height() / 2 ���� �����մϴ�.dc.MoveTo(), dc.LineTo() �Լ��� �̿��Ͽ� �����쿡 + ǥ�ø� ���ݴϴ�.

    CArray<POINT, POINT&> carray; �� �����ϰ� double PI = 3.14159265; �� �����մϴ�.

    for���� ����Ͽ� POINT pt ��ü�� x, y���� cos() ������ �����ϰ� array�� �߰��մϴ�.

    ���������� dc.Polyline(array.GetData(), array.GetSize()); �� ���� �ٰ����� �׷��ָ� �ϼ��˴ϴ�.

    //12��
    11�� ����ó�� GetClientRect(&rect)�� MoveTo(), LineTo() �Լ��� ����Ͽ�, POINT points[] = { } �� dc.Polyine() �̿��� ������ �׷��ݴϴ�.

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
//13��
CFont::CreatePointFont() �Լ����� ���ڸ� _T("���� ���") ������ �����ϸ� ��µ˴ϴ�.

//14��
CFont::CreatePointFont() �Լ����� ���ڸ� FW_BOLD �� �ϸ� ����ü�� ��µ˴ϴ�.������ ��� TRUE / FALSE�� ���� ���Ÿ��� ���� ��Ʈ�� ����� �� �ֽ��ϴ�.

//15��
CFont::CreatePointFontW(-::MulDiv(10, GetDeviceCaps(dc.m_hDC, LOGPIXELSY), 72)-- -

    10, 12, 14�� ���� �ش� ������ ũ�⸦ ������ �� �ֽ��ϴ�.

    //16��
    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)
    //17��
    ����������

    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    �޼��� ó���⿡ ���� CDC::SetMapMode() �Լ��� ���Ͽ� ���� ��带 ��ȯ�ϸ� �ȴ�.->Invalidate(false) ����

    //18��
    CChildView::OnLButtonDown(UINT nFlags, CPoint point)

    CChildView::OnRButtonDown(UINT nFlags, CPoint point)

    �޼��� ó���⿡ CPen Ŭ���� �����ڿ��� ù��° �μ��� �����ϸ� �����Ѵ�.->Invalidate(false) ����

    //19��
    GetClientRect(&rect); �� ����Ͽ� ������ �簢���� �����´�.

    CPen pen(PS_NULL, 1, RGB(0, 0, 0); ���� NULL ���� ����Ͽ� �ܰ����� ��½�Ű�� �ʴ´�.

        CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0); �� ����Ͽ� �簢���� �׸���.

    //20��
            CChildView::PreCreateWindow(CREATESTRUCT & cs) �Լ� ����

            CBitmap bitmap;

bitmap.LoadBitmapW(IDB_BITMAP1);

HBRUSH brush = CreatePatternBrush(bitmap);

����Ͽ� AfxRegisterWndClass() ���ڿ� brush ��ü�� �־��ش�.
//21��
dc.SelectStockObject() �Լ��� ����Ͽ� ANSI_FIXED_FONT / ANSI_VAR_FONT�� ����Ͽ� TextOutW()�Լ��� ���� ����Ѵ�.

//22��
CChildView::OnLButtonDown(UINT nFlags, CPoint point) �Լ���

CClientDC�� �����ϰ� CBitmap ��ü�� �����ϰ� BITMAP bmpinfo ��ü�� �����Ѵ�.

dc.StretchBlt(10, 10, bmpinfo.bmWidth * 10, bmpinfo.Height * 10, &mem, 0, 0, bmpinfo.bmWidth, bmpinfo.bm.Height, SRCCOPY); �� ���� ��Ʈ�� ��ü�� �ø���.


//23��
CChildView::OnLButtonDown(UINT nFlags, CPoint point) �Լ���

dc.StretchBlt(10 + bmpinfo.bmWidth - 1, bmpinfo.bmHeight - 1, -bmpinfo.bmWidth, -bmpinfo.Height, &mem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY); ���� �μ��� �����Ͽ� ��Ʈ���� �Ųٷ� ����Ѵ�.

//24��
��ģ ������ ���ؼ� CBrush brush(RGB(255, 0, 0)); ��ü�� �����ϰ� dc.FillRgn(&rgn1, &brush); �� ���� ä���Ѵ�.

