//1��
Resource�� �����Ͽ� IDS_APP_TITLE ĸ���� World�� �����ϸ� �ȴ�.

//2��
�켱 ���������� Resource�� �����Ͽ� IDS_APP_TITLE ĸ���� ���� �ַܼ� �����Ѵ�.

_tsetlocale("LC_ALL", _T(""));

�� �ڵ带 �����ϸ� �����ڵ尡 ����Ǿ� �ѱ��� �ܼ� â�� ����ȴ�.

//3��
IDS_MESSAGE�� �߰��ϰ� LoadString�� ���Ͽ� �о���� �ȴ�
//4��
CString str;

CString buff;

Cstring name("���� �̸�"); �� �����Ѵ�.

buff.LoadString(IDS_FORMAT); �� ����Ͽ� ���ҽ��� �о����

str.Format(buff, name, 27); �� ����Ͽ� string ������ �����ϰ� ����Ѵ�.

�޼��� ���ڷ� ����ε�..��Ծ��׿�..
//5��
TCHAR szBuf[1024];

_tscanf_s(_T("%s"), szBuf, (UINT)_countof(szBuf)); �� ����Ͽ� �켱 �����ڸ� �о�ɴϴ�.



CString str = (LPCTSTR)szBuf; �� �� ��ȯ�� �����մϴ�.

MessageBox(NULL, str.MakeLower(), _T(""), MB_OK); �� ���Ͽ� ȭ�鿡 ����մϴ�.

//6��
���������� CString str = (LPCTSTR)szBuf; �� ����ȯ�� �����մϴ�.

str.Replace(_T("�ϼ���"), _T("�Ͻÿ�")); replace�Լ��� ���� ���ڿ� ���� �� ��,

MessageBox(NULL, str, _T(""), MB_OK)�� ���Ͽ� ȭ�鿡 ����մϴ�.

//7��
CString first = _tstoi(str.Left(str.Find(_T("+"))));

CString second = _tstoi(str.Mid(str.Find(_T("+))));

	str.Left() + str.Find() �Լ��� ���� + �տ� �ִ� ���ڸ� first ��ü�� �ְ� _tstoi() �Լ��� ���� ���ڷ� �ٲ۴�.

	str.Mid() + str.Find() �Լ��� ���� + �ڿ� �ִ� ���ڸ� second ��ü�� �ְ� ���ڷ� �ٲߴϴ�.



	int sum = first + second; �� ���� �� ��,

	CString result;

result.Format(_T("%d"), sum); �� ���� ���ڸ� �ٽ� ���ڿ��� ��ȯ�Ѵ�.

MessageBox(NULL, result, _T(""), MB_OK);

���ڿ��� ���� ��ȯ�� ��, Format()�� ����Ͽ� ���Ӱ� ���ڿ��� �����ϸ� ���ϴ�.
//8��
CRect rect{ 120, 60, 270, 270 }; CRect rect ��ü�� �����ڸ� ���� �ʱ�ȭ �մϴ�

CPoint pt;

pt = rect.CenterPoint(); �Լ��� ���ؼ� �簢���� �߽��� ��ȯ �޽��ϴ�.

(���� �簢���� �ٸ��� �ʱ�ȭ �߽��ϴ�.)

//9��
CRect rect {
	120, 60, 270, 270
};

_tprintf(_T("�簢�� �ʺ� : %d �簢�� ���� : %d \n"), rect.width(), rect.height());
//10��
CRect rect{ 120, 50, 280, 110 };

rect.OffsetRect(47, 130);

_tprintf(_T("�簢�� left : %d, �簢�� top : %d, �簢�� right : %d, �簢�� bottom : %d"), rect.left, rect.top, rect.right, rect.bottom);

//11��
CPoint pt;

_tscanf_s(_T("%d, %d"), &pt.x, &pt.y);

if (rect.PtInRect(pt))

_tprintf(_T("�簢�� ���� \n"));

else

_tprintf(_T("�簢�� �ܺ� \n"));

//12��
if (rect.IsRectEmpty())

_tprintf(_T("���� \n"));

else {

	rect.NormalizeRect();

	_tprintf(_T("������ �簢�� ------"));

}
//13��
Cstring str;

CTime tm;

tm = GetCurrentTime();

str.Format(_T("%04d-%02d-%02d %02d:%02d:%02d \n"), tm.GetYear(), tm.GetMonth(), tm.GetDay(), tm.GetHour(), tm.GetMinute(), tm.GetSecond());

//14��
CString str;

CTime tm;

tm = GetCurrentTime();

str = tm.FormatGmt(_T("%A %B %d %Y"));

_tprintf(str);

����� ���߱� ���� string Format() �Լ��� �ƴ� CTime�� FormatGmt() �Լ��� ����Ͽ� ��� ����� �����.


//15��

CTime tm;

CTime result;

tm = GetCurrentTime();



CTimeSpan cs(1000, 0, 0, 0);

result = tm + cs;

printf("%04�� %02d�� %02d�� \n", result.GetYear(), result.GetMonth(), result.GetDay());

//17��
struct Point3DColor {

	int x, y, z;

	COLORREF color;



	Point3DColor() {}

	Point3DColor(int x0, int y0, int z0, COLORREF color) { x = x0; y = y0; z = z0; color = 0; }

};

����ü�� COLORREF color�� �߰�����,

CArray<Point3DColor, Point3DColor&> array;

array.SetSize(5);

... ... ��½�

for (int i = 0; i < 5; i++) {

	Point3DColor pt = array[i];

	_tprintf(_T("%d %d %d"), pt.x, pt.y, pt.z);

	_tprintf(_T("R: %d, G : %d, B : %d \n"), GetRValue(pt.color), GetGValue(pt.color), GetBValue(pt.color));

	//18��
	TCHAR* Fruit[] = { _T("���"), _T("����"), _T("����"), _T("������"), _T("�ڵ�") };



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
	//19��
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

//20��
	emplate<> UINT AFXAPI HashKey(CString& str) {

		LPCTSTR key = (LPCTSTR)str;

		return HashKey(key);

	}  �������� �������� �����Ѵ�.



		CMap<CString, CString&, UINT, UINT&> map;

	map[CString(_T("����ȯ"))] = 172; ...������ map�� �����Ѵ�.



		TCHAR szName[100];

	UINT height;

	_tscanf_s(_T("%s"), szName, (UINT)_countof(szName));



	if (map.Lookup(CString(szName), height))

		_tprintf(_T("%s �� Ű�� %d cm �Դϴ�.\n"), szName, height);



	_tscanf_s(_T("%d"), &height);

	POSITION pos = map.GetStartPosition();



	_tprintf(_T("%d�� Ű�� ���� �л��� \n"), height);

	while (pos != NULL) {

		CString strKey;

		UINT strValue;

		map.GetNextAssoc(pos, strKey, strValue);

		if (height == strValue)

			_tprintf(_T("%s "), (LPCTSTR)strKey);

	}