//1��
Resource�� �����Ͽ� IDR_MAINFRAME ĸ���� �������� ������ ������ �����ϸ� �Ϸ�ȴ�.

//2��
���콺 ��ü�� ĸ�İ� ���� �ʱ⿡ ���� �����غ��ٸ� ���콺 Ŀ���� ����Ǵ� ���� Ȯ���� �� �ִ�.

�켱 View ������ ���� ��°� ���õǱ� ������ ChildView.cpp���� ó���ؾ��մϴ�.

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ�

cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS VREDRAW | CS_DBLCLKS,

    ::LoadCursor(nullptr, IDC_HAND), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

LoadCursor() ���ڸ� IDC_HAND�� �����ϸ� �ȴ�.

//3��
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT::style ������ �����ϸ� �ȴ�.cs.style |= WS_HSCROLL | WS_VSCROLL;

(&= ���ſ� ���õ� ������ �����ϴ� �������̰� |= �߰��� ���õ� ������ �����ϴ� �������Դϴ�.) - ���� ����

//4��
�����Ӱ� ���õǾ� ��Ÿ���� �����ؾ��ϱ� ������ CMainFrame()�� �����ؾ��մϴ�.

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT::style ������ �����ϸ� �ȴ�.cs.style &= ~WS_SYSMENU;

//5��
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT::style ������ �����ϸ� �ȴ�.cs.style &= ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX;

//6��
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT ����ü ������ �̿��ϸ� ���� �ذ��� �� �ִ�.cs.x = 100; cs.y = 200;

//7��
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT ����ü ������ �̿��ϸ� ���� �ذ��� �� �ִ�.cs.cx = 100; cs.cy = 200;

//8��
�켱 �˾� �����츦 ������ ��, ��ġ�� ũ�� ������ �ʿ��ϴ�.

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� ��ġ�� ũ�⸦ �����ϰ� CREATESTRUCT style�� �����Ͽ� �ذ��Ѵ�.

cs.cx = 100; cs.cy = 200;

cs.style |= WS_POPUPWINDOW | WS_CATION | WS_OVERLAPPEDWINDOW;
//9��
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } �� �����Ͽ� CREATESTRUCT::dwExStyle ������ �����ϸ� �ȴ�.cs.dwExStyle |= WS_EX_TOPMOST;

//10��
������ø����̼� �������� �����ϱ� ������ CSimpleApp::InitInstance() �Լ������� CWnd::ShowWindow() �Լ� ���ڸ� �����Ѵ�.CFrameWnd* pFrame = new CMainFrame;

m_pMainWnd = pFrame; // �������� ����� ���ҽ��� �Բ� �ε��մϴ�.

pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr, nullptr);

pFrame->ShowWindow(SW_SHOWMINIMIZED);
//11��
pFrame->ShowWindow(SW_SHOWMAXIMIZED);

//12��
void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWinApp* cwa = AfxGetApp(); //�� ������ �޾ƿ´�.

    dc.TextOutW(50, 50, cwa->m_pszExeName);

}
//13��
void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWinApp* cwa = AfxGetApp(); //�� ������ �޾ƿ´�.

    dc.TextOutW(50, 50, cwa->m_lpCmdLine);

}//14��

void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWnd* cw = AfxGetMainWnd(); //������ ������ �޾ƿ´�.

    CString titile;

    cw->GetWindowTextW(title);

    dc.TextOutW(50, 50, title);

}
//15��
�켱 MainFrame.h ���� DECLARE_DYNCREATE(CMainFrame) ���� �����Ų��.
�� ���� MainFrame.cpp ���� IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd); �� �����Ų��.
Simple.cpp�� CSimpleApp::InitInstance() ���� CRuntimeClass::CreateObject() �Լ��� �����Ѵ�.

//16��
int CSimpleApp::ExitInstance() {

    MessageBox(NULL, _T("���α׷��� �����մϴ�."), _T("����"), NULL);

    return CWinApp::ExitInstance();

}
//17��
CMainFrame::PreCreateWindow(CREATESTRUCT& cs)�� CWinApp::GetProfileInt() �Լ��� ���� ������Ʈ ���� �����´�

//18��
�����츦 �����ϸ� �� ��� �������� ��ġ�� ���� ������ �������Ϳ� �����Ѵ�.


