//1��
WNDCLASS�� ���ؼ� style �Ӽ� ���� CS_NOCLOSE�� �����ϸ� �ȴ�.

WNDCLASS wndclass;

wndclass.style = CS_NOCLOSE;

CS_VREDRAW: ������ ũ�Ⱑ ����Ǹ� �����츦 �ٽ� �׸���.
CS_HREDRAW : ������ ũ�Ⱑ ����Ǹ� �����츦 �ٽ� �׸���.
CS_DBLCLKS : ������ ���� ���� Ŭ�� �޼����� ������ ���ν����� ������.
CS_OWNDC : Ŭ���� ������ �� �����쿡 ������ DC�� �Ҵ� �ȴ�.
CS_CLASSDE : Ŭ���� ������ �� ������� �ϳ��� DC�� �����ϰ� �ȴ�.
CS_PARENTDC : �θ� �����쿡 �簢���� ����� �ڽ��� �θ� �����쿡 �׸� �� �ְ� �Ѵ�.
CS_NOCLOSE : ������ �޴��� �ݱ� ��ư �� Ȱ��ȭ
CS_SAVEBITS : ������ ��ũ���� �Ϻθ� ��Ʈ������ �����Ѵ�.
CS_BYTEALIGNCLIENT : �������� Ŭ���̾�Ʈ ������ ����Ʈ ��迡 ����
CS_BYTEALIGNWINDOW : �����츦 ����Ʈ ��迡 �����Ѵ�.
CS_IME : IME ����� �������̽��� ����� IME ������� ����

//2��
WNDCLASS�� ���� hIcon �Ӽ� ���� IDC_QUESTION�� �����ϸ� �ȴ�.

WNDCLASS wndclass;

wndclass.hIcon = LoadIcon(NULL, IDI_QUESTION);

IDI_ASTERISK: ���� ���
IDI_ERROR : ���� ���
IDI_EXCLAMATION : ��� ���
IDI_QUESTION : ���� ���

//3��
WNDCLASS�� ���� hCursor �Ӽ� ���� IDC_ARROW�� �����ϸ� �ȴ�.

WNDCLASS wndclass;

wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

IDC_ARROW: ȭ��ǥ ���
IDC_CROSS : ũ�ν� ���
IDC_IBEAM : I ���
IDC_NO : X ���
IDC_WAIT : �𷡽ð� ���

//4��
WNDCLASS�� ���� hbrBackground �Ӽ� ���� BLACK_BRUSH�� �����ϸ� �ȴ�.

WNDCLASS wndclass;

wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);



���, ������, ȸ���� ��� �⺻ �귯�� ���� �����ϸ� �ȴ�.

RGB �������� ���� : CreateSolidBrush(RGB(10, 20, 30))
NULL ������ ������ ���� WM_ERASEBKGND �޽������� ���� ����� ����
//5��
HWND�� ���� CreateWindow() �Լ� ���� WS_CAPTION, 0, 0, 500, 200 ���� ����

HWND hwnd;

hwnd = CreateWindow(TEXT("����"), TEXT("����"), WS_CAPTION, , 0, 500, 200, NULL, NULL, hInstance, NULL);

WS_OVERLAPPEDWINDOW: �޴�, �ִ�ȭ, �ּ�ȭ ��ư ��� ������ ������
WS_CAPTION : ���� ǥ���� ǥ��
WS_HSCROLL : ���� ��ũ�ѹ� ǥ��
WS_VSCROLL : ���� ��ũ�ѹ� ǥ��
WS_MAXIMIZEBOX : �ִ�ȭ ��ư ǥ��
WS_MINIMIZEBOX : �ּ�ȭ ��ư ǥ��
WS_SYSMENU : �ý��� �޴� ǥ��
WS_THICKFRAME : ũ�� ���� ������ ǥ��
//7��
ShowWindow() �Լ� ���ڸ� SW_MAXIMIZE�� ����

ShowWindow(hwnd, SW_MAXIMIZE);

SW_HIDE: ������ ����
SW_MINIMIZE : ������ �ּ�ȭ
SW_RESTORE : ������ Ȱ��ȭ
SW_SHOW : ������ ǥ��
SW_SHOWNORMAL : ������ Ȱ��ȭ �� ǥ��

//8�� 
MessageBox() �Լ� 3��° ���ڸ� MB_YESNO�� ����

MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("���콺 �޼���"), MB_YESNO);

MB_OK: Ȯ�� ��ư ����
MB_OKCANCEL : Ȯ�� ��� ��ư ����
MB_RETRYCANCEL : �ٽýõ� ��� ��ư ����
MB_YESNO : �� �ƴϿ� ��ư ����
MB_YESNOCANCEL : �� �ƴϿ� ��� ��ư ����

//9��
MessageBox() �Լ� 3��° ���ڸ� MB_ICONSTOP���� ����

MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("���콺 �޼���"), MB_ICONSTOP);

MB_ICONEXCLAMATION / MB_ICONWARNING : ��� ������
MB_ICONINFORMATION / MB_ICONASTERISK : ���� ������
MB_ICONQUESTION : ����ǥ ������
MB_ICONSTOP / MB_ICONERROR : ���� ������

//10��
MessageBox return ���� �̿��Ͽ� ���α׷� ������ ó���Ѵ�.

if (IDOK == MessageBox(hwnd, TEXT("�����Ͻðڽ��ϱ�?"), TEXT("���콺 �޼���"), MB_OKCANCEL)) {

    PostQuitMessage(0);

    return 0;

}

IDCANCEL: ��� ��ư ���� ���
IDNO : �ƴϿ� ��ư ���� ���
IDRETRY : �ٽýõ� ��ư�� ���� ���
IDOK : Ȯ�� ��ư ���� ���
IDYES : �� ��ư�� ���� ���
//13��
ShowWindow() �Լ� ���ڸ� SW_MAXIMIZE�� �����Ѵ�.

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {

    ShowWindow(SW_MAXIMIZE);

}
//17��
void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {

    if (IDOK == MessageBox(_T("�����Ͻðڽ��ϱ�?"), _T("���콺 �޼���"), MB_OKCANCEL))

        DestroyWindow();

}