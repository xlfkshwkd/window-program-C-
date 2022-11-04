//1번
WNDCLASS에 대해서 style 속성 값을 CS_NOCLOSE로 설정하면 된다.

WNDCLASS wndclass;

wndclass.style = CS_NOCLOSE;

CS_VREDRAW: 세로의 크기가 변경되면 윈도우를 다시 그린다.
CS_HREDRAW : 가로의 크기가 변경되면 윈도우를 다시 그린다.
CS_DBLCLKS : 윈도우 내부 더블 클릭 메세지를 윈도우 프로시저로 보낸다.
CS_OWNDC : 클래스 내부의 각 윈도우에 고유의 DC가 할당 된다.
CS_CLASSDE : 클래스 내부의 각 윈도우는 하나의 DC를 공유하게 된다.
CS_PARENTDC : 부모 윈도우에 사각형을 만들어 자식이 부모 윈도우에 그릴 수 있게 한다.
CS_NOCLOSE : 윈도우 메뉴의 닫기 버튼 비 활성화
CS_SAVEBITS : 가려진 스크린의 일부를 비트맵으로 저장한다.
CS_BYTEALIGNCLIENT : 윈도우의 클라이언트 영역을 바이트 경계에 정렬
CS_BYTEALIGNWINDOW : 윈도우를 바이트 경계에 정렬한다.
CS_IME : IME 사용자 인터페이스에 사용할 IME 윈도우로 지정

//2번
WNDCLASS에 대해 hIcon 속성 값을 IDC_QUESTION로 설정하면 된다.

WNDCLASS wndclass;

wndclass.hIcon = LoadIcon(NULL, IDI_QUESTION);

IDI_ASTERISK: 정보 모양
IDI_ERROR : 에러 모양
IDI_EXCLAMATION : 경고 모양
IDI_QUESTION : 질문 모양

//3번
WNDCLASS에 대해 hCursor 속성 값을 IDC_ARROW로 설정하면 된다.

WNDCLASS wndclass;

wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

IDC_ARROW: 화살표 모양
IDC_CROSS : 크로스 모양
IDC_IBEAM : I 모양
IDC_NO : X 모양
IDC_WAIT : 모래시계 모양

//4번
WNDCLASS에 대해 hbrBackground 속성 값을 BLACK_BRUSH로 설정하면 된다.

WNDCLASS wndclass;

wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);



흰색, 검정색, 회색의 경우 기본 브러시 값만 변경하면 된다.

RGB 색상으로 지정 : CreateSolidBrush(RGB(10, 20, 30))
NULL 값으로 지정할 경우는 WM_ERASEBKGND 메시지에서 직접 배경을 설정
//5번
HWND에 대해 CreateWindow() 함수 인자 WS_CAPTION, 0, 0, 500, 200 으로 설정

HWND hwnd;

hwnd = CreateWindow(TEXT("예제"), TEXT("예제"), WS_CAPTION, , 0, 500, 200, NULL, NULL, hInstance, NULL);

WS_OVERLAPPEDWINDOW: 메뉴, 최대화, 최소화 버튼 등등 포함한 윈도우
WS_CAPTION : 제목 표시줄 표시
WS_HSCROLL : 수평 스크롤바 표시
WS_VSCROLL : 수직 스크롤바 표시
WS_MAXIMIZEBOX : 최대화 버튼 표시
WS_MINIMIZEBOX : 최소화 버튼 표시
WS_SYSMENU : 시스템 메뉴 표시
WS_THICKFRAME : 크기 조절 프레임 표시
//7번
ShowWindow() 함수 인자를 SW_MAXIMIZE로 설정

ShowWindow(hwnd, SW_MAXIMIZE);

SW_HIDE: 윈도우 숨김
SW_MINIMIZE : 윈도우 최소화
SW_RESTORE : 윈도우 활성화
SW_SHOW : 윈도우 표시
SW_SHOWNORMAL : 윈도우 활성화 후 표시

//8번 
MessageBox() 함수 3번째 인자를 MB_YESNO로 설정

MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_YESNO);

MB_OK: 확인 버튼 생성
MB_OKCANCEL : 확인 취소 버튼 생성
MB_RETRYCANCEL : 다시시도 취소 버튼 생성
MB_YESNO : 예 아니오 버튼 생성
MB_YESNOCANCEL : 예 아니오 취소 버튼 생성

//9번
MessageBox() 함수 3번째 인자를 MB_ICONSTOP으로 설정

MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_ICONSTOP);

MB_ICONEXCLAMATION / MB_ICONWARNING : 경고 아이콘
MB_ICONINFORMATION / MB_ICONASTERISK : 정보 아이콘
MB_ICONQUESTION : 물음표 아이콘
MB_ICONSTOP / MB_ICONERROR : 정지 아이콘

//10번
MessageBox return 값을 이용하여 프로그램 로직을 처리한다.

if (IDOK == MessageBox(hwnd, TEXT("종료하시겠습니까?"), TEXT("마우스 메세지"), MB_OKCANCEL)) {

    PostQuitMessage(0);

    return 0;

}

IDCANCEL: 취소 버튼 누른 경우
IDNO : 아니오 버튼 누른 경우
IDRETRY : 다시시도 버튼을 누른 경우
IDOK : 확인 버튼 누른 경우
IDYES : 예 버튼을 누른 경우
//13번
ShowWindow() 함수 인자를 SW_MAXIMIZE로 설정한다.

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {

    ShowWindow(SW_MAXIMIZE);

}
//17번
void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {

    if (IDOK == MessageBox(_T("종료하시겠습니까?"), _T("마우스 메세지"), MB_OKCANCEL))

        DestroyWindow();

}