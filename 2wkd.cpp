//1번
Resource에 접근하여 IDS_APP_TITLE 캡션을 World로 수정하면 된다.

//2번
우선 마찬가지로 Resource에 접근하여 IDS_APP_TITLE 캡션의 값을 콘솔로 변경한다.

_tsetlocale("LC_ALL", _T(""));

위 코드를 삽입하면 유니코드가 적용되어 한글이 콘솔 창에 실행된다.

//3번
IDS_MESSAGE를 추가하고 LoadString을 통하여 읽어오면 된다
//4번
CString str;

CString buff;

Cstring name("본인 이름"); 을 선언한다.

buff.LoadString(IDS_FORMAT); 을 사용하여 리소스를 읽어오고

str.Format(buff, name, 27); 을 사용하여 string 포멧을 설정하고 출력한다.

메세지 상자로 출력인데..까먹었네요..
//5번
TCHAR szBuf[1024];

_tscanf_s(_T("%s"), szBuf, (UINT)_countof(szBuf)); 를 사용하여 우선 영문자를 읽어옵니다.



CString str = (LPCTSTR)szBuf; 로 형 변환을 적용합니다.

MessageBox(NULL, str.MakeLower(), _T(""), MB_OK); 를 통하여 화면에 출력합니다.

//6번
마찬가지로 CString str = (LPCTSTR)szBuf; 로 형변환을 적용합니다.

str.Replace(_T("하세요"), _T("하시오")); replace함수를 통해 문자열 변경 한 후,

MessageBox(NULL, str, _T(""), MB_OK)를 통하여 화면에 출력합니다.

//7번
CString first = _tstoi(str.Left(str.Find(_T("+"))));

CString second = _tstoi(str.Mid(str.Find(_T("+))));

	str.Left() + str.Find() 함수를 통해 + 앞에 있는 글자를 first 객체에 넣고 _tstoi() 함수를 통해 숫자로 바꾼다.

	str.Mid() + str.Find() 함수를 통해 + 뒤에 있는 글자를 second 객체에 넣고 숫자로 바꿉니다.



	int sum = first + second; 를 진행 한 후,

	CString result;

result.Format(_T("%d"), sum); 을 통해 숫자를 다시 문자열로 변환한다.

MessageBox(NULL, result, _T(""), MB_OK);

문자열로 보통 변환할 땐, Format()을 사용하여 새롭게 문자열을 정의하면 편하다.
//8번
CRect rect{ 120, 60, 270, 270 }; CRect rect 객체를 생성자를 통해 초기화 합니다

CPoint pt;

pt = rect.CenterPoint(); 함수를 통해서 사각형의 중심을 반환 받습니다.

(제가 사각형을 다르게 초기화 했습니다.)

//9번
CRect rect {
	120, 60, 270, 270
};

_tprintf(_T("사각형 너비 : %d 사각형 높이 : %d \n"), rect.width(), rect.height());
//10번
CRect rect{ 120, 50, 280, 110 };

rect.OffsetRect(47, 130);

_tprintf(_T("사각형 left : %d, 사각형 top : %d, 사각형 right : %d, 사각형 bottom : %d"), rect.left, rect.top, rect.right, rect.bottom);

//11번
CPoint pt;

_tscanf_s(_T("%d, %d"), &pt.x, &pt.y);

if (rect.PtInRect(pt))

_tprintf(_T("사각형 내부 \n"));

else

_tprintf(_T("사각형 외부 \n"));

//12번
if (rect.IsRectEmpty())

_tprintf(_T("정상 \n"));

else {

	rect.NormalizeRect();

	_tprintf(_T("수정된 사각형 ------"));

}
//13번
Cstring str;

CTime tm;

tm = GetCurrentTime();

str.Format(_T("%04d-%02d-%02d %02d:%02d:%02d \n"), tm.GetYear(), tm.GetMonth(), tm.GetDay(), tm.GetHour(), tm.GetMinute(), tm.GetSecond());

//14번
CString str;

CTime tm;

tm = GetCurrentTime();

str = tm.FormatGmt(_T("%A %B %d %Y"));

_tprintf(str);

양식을 맞추기 위해 string Format() 함수가 아닌 CTime의 FormatGmt() 함수를 사용하여 출력 양식을 맞춘다.


//15번

CTime tm;

CTime result;

tm = GetCurrentTime();



CTimeSpan cs(1000, 0, 0, 0);

result = tm + cs;

printf("%04년 %02d월 %02d일 \n", result.GetYear(), result.GetMonth(), result.GetDay());

//17번
struct Point3DColor {

	int x, y, z;

	COLORREF color;



	Point3DColor() {}

	Point3DColor(int x0, int y0, int z0, COLORREF color) { x = x0; y = y0; z = z0; color = 0; }

};

구조체에 COLORREF color를 추가한후,

CArray<Point3DColor, Point3DColor&> array;

array.SetSize(5);

... ... 출력시

for (int i = 0; i < 5; i++) {

	Point3DColor pt = array[i];

	_tprintf(_T("%d %d %d"), pt.x, pt.y, pt.z);

	_tprintf(_T("R: %d, G : %d, B : %d \n"), GetRValue(pt.color), GetGValue(pt.color), GetBValue(pt.color));

	//18번
	TCHAR* Fruit[] = { _T("사과"), _T("딸기"), _T("포도"), _T("오렌지"), _T("자두") };



	CList<CString, LPCTSTR> list;

	for (int i = 0; i < 5; i++) {

		list.AddTail(CString((LPCTSTR)Fruit[i]));

	}

	POSITION pos = list.GetHeadPosition();

	while (pos != NULL) {

		CString str = list.GetNext(pos);

		_tprintf(str);

		_tprintf(_T("\n");

	}
	//19번
	CList <UINT, UINT&> cl;

	for (int i = 0; i < 10; i++) {

		cl.AddTail(UINT(i));

	}



	POSITION pos;



	while (!cl.IsEmpty()) {

		UINT nItem = 0;

		_tscanf_s(_T("%d"), &nItem);



		pos = cl.Find(nItem);

		cl.RemoveAt(pos);

		pos = cl.GetHeadPosition();



		while (pos != NULL) {

			CString str;

			str.Format(_T("%d "), cl.GetNext(pos));

			_tprintf(str);

		}

		_tprintf(_T("\n"));

	}

//20번
	emplate<> UINT AFXAPI HashKey(CString& str) {

		LPCTSTR key = (LPCTSTR)str;

		return HashKey(key);

	}  전역으로 템프릿을 제작한다.



		CMap<CString, CString&, UINT, UINT&> map;

	map[CString(_T("전승환"))] = 172; ...식으로 map을 세팅한다.



		TCHAR szName[100];

	UINT height;

	_tscanf_s(_T("%s"), szName, (UINT)_countof(szName));



	if (map.Lookup(CString(szName), height))

		_tprintf(_T("%s 의 키는 %d cm 입니다.\n"), szName, height);



	_tscanf_s(_T("%d"), &height);

	POSITION pos = map.GetStartPosition();



	_tprintf(_T("%d의 키를 가진 학생들 \n"), height);

	while (pos != NULL) {

		CString strKey;

		UINT strValue;

		map.GetNextAssoc(pos, strKey, strValue);

		if (height == strValue)

			_tprintf(_T("%s "), (LPCTSTR)strKey);

	}