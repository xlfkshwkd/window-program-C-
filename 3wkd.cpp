//1번
Resource에 접근하여 IDR_MAINFRAME 캡션을 문제에서 정의한 값으로 변경하면 완료된다.

//2번
마우스 자체는 캡쳐가 되지 않기에 직접 구현해본다면 마우스 커서가 변경되는 것을 확인할 수 있다.

우선 View 영역에 대한 출력과 관련되기 때문에 ChildView.cpp에서 처리해야합니다.

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여

cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS VREDRAW | CS_DBLCLKS,

    ::LoadCursor(nullptr, IDC_HAND), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

LoadCursor() 인자를 IDC_HAND로 변경하면 된다.

//3번
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT::style 변수를 조작하면 된다.cs.style |= WS_HSCROLL | WS_VSCROLL;

(&= 제거와 관련된 연산을 수행하는 연산자이고 |= 추가와 관련된 연산을 수행하는 연산자입니다.) - 논리로 생각

//4번
프레임과 관련되어 스타일을 조작해야하기 때문에 CMainFrame()에 접근해야합니다.

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT::style 변수를 조작하면 된다.cs.style &= ~WS_SYSMENU;

//5번
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT::style 변수를 조작하면 된다.cs.style &= ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX;

//6번
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT 구조체 변수를 이용하면 쉽게 해결할 수 있다.cs.x = 100; cs.y = 200;

//7번
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT 구조체 변수를 이용하면 쉽게 해결할 수 있다.cs.cx = 100; cs.cy = 200;

//8번
우선 팝업 윈도우를 생성할 땐, 위치와 크기 지정이 필요하다.

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 위치와 크기를 설정하고 CREATESTRUCT style을 설정하여 해결한다.

cs.cx = 100; cs.cy = 200;

cs.style |= WS_POPUPWINDOW | WS_CATION | WS_OVERLAPPEDWINDOW;
//9번
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs) { } 에 접근하여 CREATESTRUCT::dwExStyle 변수를 설정하면 된다.cs.dwExStyle |= WS_EX_TOPMOST;

//10번
응용어플리케이션 관점에서 설장하기 때문에 CSimpleApp::InitInstance() 함수내에서 CWnd::ShowWindow() 함수 인자를 설정한다.CFrameWnd* pFrame = new CMainFrame;

m_pMainWnd = pFrame; // 프로임을 만들어 리소스와 함께 로드합니다.

pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr, nullptr);

pFrame->ShowWindow(SW_SHOWMINIMIZED);
//11번
pFrame->ShowWindow(SW_SHOWMAXIMIZED);

//12번
void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWinApp* cwa = AfxGetApp(); //앱 정보를 받아온다.

    dc.TextOutW(50, 50, cwa->m_pszExeName);

}
//13번
void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWinApp* cwa = AfxGetApp(); //앱 정보를 받아온다.

    dc.TextOutW(50, 50, cwa->m_lpCmdLine);

}//14번

void CChildView::OnPaint() {

    CPaintDC dc(this);

    CWnd* cw = AfxGetMainWnd(); //프레임 정보를 받아온다.

    CString titile;

    cw->GetWindowTextW(title);

    dc.TextOutW(50, 50, title);

}
//15번
우선 MainFrame.h 에서 DECLARE_DYNCREATE(CMainFrame) 으로 변경시킨다.
그 다음 MainFrame.cpp 에서 IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd); 로 변경시킨다.
Simple.cpp의 CSimpleApp::InitInstance() 에서 CRuntimeClass::CreateObject() 함수로 생성한다.

//16번
int CSimpleApp::ExitInstance() {

    MessageBox(NULL, _T("프로그램을 종료합니다."), _T("종료"), NULL);

    return CWinApp::ExitInstance();

}
//17번
CMainFrame::PreCreateWindow(CREATESTRUCT& cs)에 CWinApp::GetProfileInt() 함수를 통해 레지스트 값을 가져온다

//18번
윈도우를 종료하면 그 당시 윈도우의 위치에 관한 정보를 레지스터에 저장한다.


