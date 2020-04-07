// samplesource.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

//#include:疑似命令
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <stddef.h>
#include <cstdlib>
#include "maindefs.h"
#include "file.h"
#include "textfile.h"
#include "BinFile.h"
#include "EnFile.h"
#include "templete.h"
#include "TestFile.h"
#include "Debug1.h"

//#define ELEM(array) (sizeof (array) / sizeof *(array))

#define offsetof(s,m)  (size_t)&(((s *)0)->m) //ヌルポインタを指定した構造体へのポインタでキャスト
											  //指定したメンバ変数を指定し、そのアドレスを取る
											  //size_t（unsigned int の同義語で、sizeof の返す値の型を表す）でキャスト
											 //構造体の先頭アドレスを０としたときのメンバ変数のアドレスを返す

#define PRINTF(a)  a##printf // ##:トークン結合子　くっついて展開される　展開時に##は消去される　引数の展開は消去されるまえに行われる

using namespace std;

const unsigned char XOR_FACTOR = 0xAA;  // 暗号化に使う数 const:クラスのメンバ変数の値を、オブジェクト作成後に変更できなくする

/*void Func()
{
	int i;
	cout << i << endl;
	i--;
	if (i > 0)
		Func(); //再帰関数
}*/

/*class CIntArray
{
private:
	int* m_pNum;
	int m_nNumOf;

public:

	/*bool Success();
	int NumOf();
	int SizeOf();

	bool Success()
	{
		return m_pNum != NULL;
	}

	// 配列の要素数
	int NumOf()
	{
		return m_nNumOf;
	}

	// 配列のサイズ
	int SizeOf()
	{
		return m_nNumOf * sizeof * m_pNum;
	}
};*/

/*inline bool CIntArray::Success()
{
	return m_pnum != NULL;
}

inline int CIntArray::NumOf() //マクロをパワーアップさせたようなもの 処理の埋め込み
{
	return m_nNumof;
}

inline int CIntArray::SizeOf()
{
	return m_nNumof * sizeof * m_pnum;
}*/

//int a = 1;

/*int strlen(char* str)
{
	int i;
	for (i = 0; str[i]; i++)
	return i;
}*/

//void Func();

/*void AddressCheck_Sub()
{
	static int a; //sattic:クラスのメンバ変数で、値をオブジェクトごとに持つのではなく、すべてのオブジェクトで同じ変数を参照したい場合に使用
	int        b;
	cout << "&a = " << &a << endl;
	cout << "&b = " << &b << endl;
}

void AddressCheck_Sub2()
{
	cout << "in Sub2" << endl;
	AddressCheck_Sub();
}

void AddressCheck()
{
	cout << "アドレスが常に一定かのチェック" << endl;

	AddressCheck_Sub();
	AddressCheck_Sub2();
	AddressCheck_Sub();
}

void InitOnceCheck_Sub()
{
	static int a = 3;
	int        b = 3;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a++;
	b++;
}

void InitOnceCheck()
{
	cout << endl << "初期化が１回しかされないかのチェック" << endl;

	InitOnceCheck_Sub();
	InitOnceCheck_Sub();
}

void ZeroInitCheck_Sub()
{
	static int a, b, c, d;
	cout << a << ',' << b << ',' << c << ',' << d << endl;
}

void ZeroInitCheck_Sub2()
{
	int a, b, c, d;
	a = b = c = d = 0;

	cout << a << ',' << b << ',' << c << ',' << d << endl;
}

void ZeroInitCheck()
{
	cout << endl << "０で初期化されるかのチェック" << endl;

	ZeroInitCheck_Sub();
	ZeroInitCheck_Sub2();
}

void HoldValueCheck_Sub(int*& pa, int*& pb)
{
	static int a = 9;
	int        b = 9;
	pa = &a;
	pb = &b;
}

void HoldValueCheck_Sub2()
{
	int dummy[100];
	memset(dummy, 0, sizeof dummy);
}

void HoldValueCheck()
{
	cout << endl << "値が保証されるかのチェック" << endl;

	int* pa, * pb;
	HoldValueCheck_Sub(pa, pb);
	HoldValueCheck_Sub2();       // この関数を呼んでも値は保証されているかな？
	cout << "*pa = " << *pa << endl;
	cout << "*pb = " << *pb << endl;
}*/

/*void Displength(const char* str)
{
	printf("文字列[%s]の長さは%dバイトです。\n", str, strlen(str));
}*/

/*void StoreFibo(int* array, int nSize)
{
	int i;

	if (nSize < 0)
		return;
	array[0] = 1;

	if (nSize == 1)
		return;
	array[1] = 1;

	for (i = 2; i < nSize; i++)
		array[i] = array[i - 1] + array[i - 2];
}

void DispFibo(const int* array, int nSize)
{
	int i;
	for (i = 0; i < nSize; i++)
		cout << array[i] << ' ';
	cout << endl;
}*/

/*struct SStudent
{
	char szName[16];
	int  nJapanese;
	int  nMath;
	int  nEnglish;
};

void Disp(const SStudent* pstudent)
{
	cout << "名前 : " << pstudent->szName << endl
		 << "国語 : " << pstudent->nJapanese << " 点, "
		    "数学 : " << pstudent->nMath << " 点, "
		    "英語 : " << pstudent->nEnglish << " 点" << endl;
}*/

/*inline void InitRand()
{
	srand((unsigned int)time(NULL));
}

inline int Dice()
{
	return rand() % 6 + 1;
}*/

/*int CTextFile::WriteString(const char* pszString)
{
	return 0;
}*/

// １行読み出す関数
// 改行コードは切り捨てられます
// 戻り値は文字列の長さになります
// バッファに入りきらないとき（オーバーフロー）は TF_OVERFLOW を返します
/*int CTextFile::ReadLine(char* buffer, size_t nSize)
{
	if (IsValid() == false)
		return EOF;
	if (fgets(buffer, nSize, m_pfile) == NULL)
		return EOF;

	size_t nLength = strlen(buffer); //オブジェクトのバイト数を表現できる程度に十分に大きい符号なし整数型である。

	// 最後に改行のない場合は、オーバーフローか、改行のない最後の行です
	// 改行のない最後の行がたまたまバッファの長さ－１の長さの時もオーバーフローと判定します
	if (buffer[nLength - 1] != '\n')
		return (nLength == nSize - 1) ? TF_OVERFLOW : nLength;

	nLength -= 1;
	buffer[nLength] = 0;
	return nLength;
}*/

bool CFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	return false;
}

// コンストラクタ クラス名と同じ名前の戻り値なしの関数
CFile::CFile()
{
	m_pfile = NULL;
	m_bCopy = false;
}

// コピーコンストラクタ
CFile::CFile(const CFile& rother)
{
	m_pfile = rother.m_pfile;
	m_bCopy = true;
}

// デストラクタ
CFile::~CFile()
{
	if (m_bCopy == false)
		Close();
}

// ファイルを開く
bool CFile::Open(const char* pszFile, const char* pszFlags)
{
	//Close();

	char bufFlags[8];

	if (ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false)
		return false;

	errno_t error;

	error = fopen_s(&m_pfile, pszFile, bufFlags);

	return (m_pfile != NULL);
}

// ファイルを閉じる
void CFile::Close()
{
	if (IsValid() == true)
	{
		fclose(m_pfile);
		m_pfile = 0;
	}
}

// フラグの調整
/*bool CFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	bool bBinary;  // 'b' の指定があるかどうか

	// strchr は、指定した文字が初めに出てくる位置を返す関数です
	// ただ単に文字が含まれているかどうかを確認するのにも使えます
	bBinary = (strchr(pszSource, 'b') != NULL);

	// フラグが多すぎるときは false を返す
	if ((int)strlen(pszSource) > nSize - 1 - !bBinary)
		return false;

	// 強制的にバイナリモードで開きます
	// strcpy は文字列をコピーする関数、strcat は文字列を追加する関数です
	strcpy_s(pszDest, 128, pszSource);
	if (bBinary == false)
		strcat_s(pszDest, 128, "b");
	return true;
}*/

// ファイルから読み出す
size_t CFile::Read(void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fread(pData, 1, nSize, m_pfile);
}

// ファイルに書き込む
size_t CFile::Write(const void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fwrite(pData, 1, nSize, m_pfile);
}

// ファイルの終端に達したかどうか
bool CFile::Eof()
{
	if (IsValid() == false)
		return true;
	return (feof(m_pfile) != 0);
}

/*void Viss(const int num)
{
	cout << "Viss : No." << num << endl;
}*/

bool Open(CFile& rfile, const char* pszFlags)
{
	char buffer[512];

	cout << "ファイル名を指定して下さい > " << flush;
	cin >> buffer;
	return rfile.Open(buffer, pszFlags);
}

/*void Write(CTextFile& rtxt)
{
	char buffer[512];

	cout << "何を書き込みますか > " << flush;
	cin >> buffer;
	rtxt.Write(buffer,128);
}*/

void Load(CFile& rbin)
{
	char buffer[512];
	int  nRead;

	nRead = rbin.Read(buffer, numof(buffer));
	buffer[nRead] = 0;
	cout << buffer << endl;
}

// 読み出し
void Read(CFile* pfile)
{
	if (pfile->Open("Test.txt", "r") == false)
		return;

	char buffer[512];

	pfile->Read(buffer, sizeof buffer);
	cout << buffer << endl;
	pfile->Close();
}

// 書き込み
void Write(CFile* pfile)
{
	if (pfile->Open("Test.txt", "w") == false)
		return;

	char buffer[] = "食すな危険";

	pfile->Write(buffer, sizeof buffer);
	pfile->Close();
}

// デフォルトコンストラクタ
CEncodeFile::CEncodeFile()
{
	cout << "CEncodeFile::CEncodeFile 1" << endl;
}

// 構築と同時にファイルを開く
CEncodeFile::CEncodeFile(const char* pszPath, const char* pszFlags)
{
	cout << "CEncodeFile::CEncodeFile 2" << endl;
	Open(pszPath, pszFlags);
}

// コピーコンストラクタ
CEncodeFile::CEncodeFile(const CEncodeFile& rother) : CBinaryFile(rother)
{
	cout << "CEncodeFile::CEncodeFile 3" << endl;
}

// デストラクタ
CEncodeFile::~CEncodeFile()
{
	cout << "CEncodeFile::~CEncodeFile" << endl;
}

// ファイルの読み出し
size_t CEncodeFile::Read(void* buffer, size_t nSize)
{
	size_t nRead;  // 読み出したバイト数

	nRead = CBinaryFile:: Read(buffer, nSize); //常に CBinaryFile の Read が呼べる
	Decode(buffer, nRead);

	return nRead;
}

// ファイルの書き込み
size_t CEncodeFile::Write(const void* buffer, size_t nSize)
{
	unsigned char* bufEncode;  // 暗号化バッファ
	size_t nWrite;  // 読み出した書き込んだバイト数

	if (nSize == EF_OUTOFMEMORY)
		return EF_OUTOFMEMORY;

	bufEncode = new unsigned char[nSize];
	if (bufEncode == NULL)
		return EF_OUTOFMEMORY;

	Encode(bufEncode, buffer, nSize);
	nWrite = CBinaryFile::Write(bufEncode, nSize); //常に CBinaryFile の Write が呼べる

	delete[] bufEncode;
	return nWrite;
}

// 暗号化
// bufDest, bufSrc の型は void*, const void* なので、
// unsigned char*, const unsigned char* でキャストしてから参照します
void CEncodeFile::Encode(void* bufDest, const void* bufSrc, size_t nSize)
{
	size_t i;

	for (i = 0; i < nSize; i++)
		((unsigned char*)bufDest)[i] =
		((const unsigned char*)bufSrc)[i] ^ XOR_FACTOR;
}

// 復号化（暗号化されたものを元に戻すこと）
void CEncodeFile::Decode(void* buffer, size_t nSize)
{
	size_t i;

	for (i = 0; i < nSize; i++)
		((unsigned char*)buffer)[i] ^= XOR_FACTOR;
}

void print(int c)
{
	cout << c;
}

/*class complex {
	double re;
	double im;
public:
	complex() : re(0), im(0) {} //complex:複素数を表すクラス
	complex(double x) { re = x, im = x; };
	complex(double x, double y) { re = x, im = y; }
	void print() { cout << re << " " << im; }
};*/

//void fun(int);
//int s(int n);

/*class complex {
	double re, im;
public:
	complex() : re(1), im(0.4) {}
	complex operator+(complex& t);
	void Print() { cout << re << " " << im; }
};
complex complex::operator+ (complex& t) {
	complex temp;
	temp.re = this->re + t.re;
	temp.im = this->im + t.im;
	return temp;
}*/

float* sum(float a, float b);

float* sum(float a, float b)
{
	float* f = new float;
	*f = a + b;
	return f;
}

int Average(const int pnValues[], const int nData)
{
	ASSERT(pnValues != NULL && nData > 0);

	int i;
	int nSum = 0;

	for (i = 0; i < nData; i++)
		nSum += pnValues[i];

	return nSum / nData;
}

/*class A {
public:
	virtual void Print() = 0;
};
class B :public A {
public:
	virtual void Print() { cout << "B"; }
};
class C :public A {
public:
	virtual void Print() { cout << "C"; }
};*/

struct s2 {
	float f; struct s2* s;
};

class fraction
{
private:
	int m_nNumer;  // 分子 (numerator)
	int m_nDenom;  // 分母 (denominator)

public:
	fraction(int nNumer = 0, int nDenom = 1)
	{
		m_nNumer = nNumer; m_nDenom = nDenom;
	}
	operator int()
	{
		return m_nNumer / m_nDenom;
	}

	friend fraction operator - (int nNum, fraction frcSub); //フレンド関数：private,protectedのモノも使うことができる　クラスも同様（フレンドクラス）
															 //フレンド指定は一方通行
};

/*class fraction
{
private:
	int m_nNumer;

public:
	fraction(int m_nNumer = 0)
	{

	}

	operator int()
	{
		return m_nNumer;
	}
};*/

fraction operator - (int nNum, fraction frcSub)
{
	fraction ret(frcSub.m_nDenom * nNum - frcSub.m_nNumer, frcSub.m_nDenom);
	return ret;
}

typedef double (*FPOP2)(double, double);  // 関数ポインタ 定数に設定 

//const FPOP2 afpOps[] = {
//	 ADD, SUB, MUL, DIV,
//};

/*class A {
public:
	void Print() { cout << "A"; }
};
class B :public A {
public:
	//virtual void Print() { cout << "B"; }
	void Print() { cout << "B"; }
};
class C :public B {
public:
	void Print() { cout << "C"; }
};*/

/*class A {
public:
	A() { cout << "A0 "; }
	A(string s) { cout << "A1"; }
};
class B : public A {
public:
	B() { cout << "B0 "; }
	B(string s) { cout << "B1 "; }
};
class C : private B {
public:
	C() { cout << "C0 "; }
	C(string s) { cout << "C1 "; }
};*/

/*class A {
public:
	int i;
};

class First
{
string* s;

public:
	First() { s = new string("Text"); }
	~First() { delete s; }

	void Print() { cout << *s; }
};*/

/*class A {
protected:
	int x;
protected:
	int y;
public:
	int z;
};

class B : private A {
	string name;
public:
	void set() {
		x = 1;
	}
	void Print() {
		cout << x;
	}
};*/

class TestClass
{
	int num;

public:

	TestClass operator+() const //単項演算子のオーバーロード
	{
		return *this;
	}

	TestClass operator-() const
	{
		TestClass tc;
		tc.num = -num;
		return tc;
	}
};

class First
{
	string name;
public:
	First() {
		name = "Alan";
	}

	void setName(string n) { this->name = n; }
	void setName() { this->name = "John"; }
	void Print() {
		cout << name;
	}
};

/*class A {
	protected:
		int y;
	public:
		int x;
		int z;

		A() { x = 2; y = 2; z = 3; }
		//A(int a, int b) : x(a), y(b) { z = x ? y; }

		void Print() {
				cout << z;
	}
};*/

#pragma pack(1) //#pragma pack(<最大バイト単位>) でアラインメントを変えることができる　１，２，４，８，１６の中から選ぶことができる
struct SPerson
{
	char  szName[21];  // 名前
	int   nAge;        // 年齢
	char  nBirthmonth; // 誕生月
	char  fSex;        // 性別
};

#pragma pack() //設定を元に戻す

/*class A {
public:
	int x;
	A() { x = 0; }
};

class B: protected A {
public:
	int y;
	using A::x; //using;class Aの中身を使用できるようにする

	B(int y) { this->y = y;}

	void Print() {cout << x << y;}
};*/

/*class A {
public:
	int age;
	A() { age = 5; };
};
class B : private A {
	string name;
public:
	B() { name = "Bob"; };
	void Print() {
		cout << name << age;
	}
};*/

class SampleClass
{
	string *s;
public:
	SampleClass() { s = new string("Text"); }
	SampleClass(string s) { this->s = new string(s); }
	~SampleClass() { delete s; }
	void Print() { cout << *s; }
};

/*class A {
public:
	void Print() { cout << "A"; }
};
class C :public A {
public:
	virtual void Print() = 0;
};*/

/*class A {
public:
	void print() {
		cout << "A ";
	}
};
class B {
public:
	void print() {
		cout << "B ";
	}
};*/

/*class complex {
	double re;
	double im;
public:
	complex() : re(1), im(0.4) {}
	bool operator==(complex& t);
};
bool complex::operator == (complex& t) {
	if ((this->re == t.re) && (this->im == t.im))
		return true;
	else
		return false;
}*/

class complex {
	double re,im;
public:
	complex() :re(0), im(0) {}
	complex(double x) { re = x, im = x; }
	complex(double x, double y) { re = x, im = y; }

	void print() { cout << re << "" << im; }
};

class A {
	int x;
protected:
	int y;
public:
	int age;
	A() { age = 5; };

};
class B:public A {
	string name;
public:
	B() { name = "Job"; };

	void Print() {
		cout << name << age << endl;
	}
};

/*void fun(int);

void fun(int n) 
{
	if (n < 2)
	{
		fun(++n);
		cout << n;
	}
}

int s(int n);

int s(int n) {
	return n + n;
}*/

int fun(int x)
{
	return 2 * x;
}

  int main()
//int mainSamplesource()
  {
	  cout << "実行" << endl; //cout:クラスのオブジェクト

	  //csv data open
	  FILE* fp1; // FILE型構造体
	  FILE* fp2;
	  char fname1[] = "C:\\Users\\tkm46\\OneDrive\\Desktop\\program\\sample1.csv";
	  char fname2[] = "C:\\Users\\tkm46\\OneDrive\\Desktop\\program\\sample2.csv";

	  int N=10;

	  // C11で導入　VisualC++2012以降ではこちらのみ使用可能
	  errno_t err1,err2; // errno_t型(int型)

	  err1 = fopen_s(&fp1, fname1, "r"); // ファイルを開く。失敗するとエラーコードを返す。
	  err2 = fopen_s(&fp2, fname2, "r"); // ファイルを開く。失敗するとエラーコードを返す。
	
	  if (err1 != NULL) {
		  printf("%s file1 not open\n", fname1);
		  return err1;
	  }
	  else {
		  printf("%s file1 opened\n", fname1);
	  }

	  if (err2 != NULL) {
		  printf("%s file2 not open\n", fname2);
		  return err2;
	  }
	  else {
		  printf("%s file2 opened\n", fname2);
	  }

	  int i,j;
	  //double tmp;
	  double ary1[10][10],ary2[10][10];

	  for (i = 0; i < N; i++) {
		  for (j = 0; j < N; j++) {
			  fscanf_s(fp1, "%lf\n", &(ary1[i][j]));
		  }
	  }

	  for (i = 0; i < N; i++) {
		  for (j = 0; j < N; j++) {
			  fscanf_s(fp2, "%lf\n", &(ary2[i][j]));
		  }
	  }

	  //printf("%lf,%lf,%lf", ary1[0], ary1[1], ary1[2]);
	  //printf("\n");

	  //printf("%lf,%lf,%lf", ary2[0], ary2[1], ary2[2]);
	  //printf("\n");

	  fclose(fp1);
	  fclose(fp2); 

	  //uppersort
	  /*for (i = 0; i < 2; i++) {
			  if (ary[i] > ary[i+1]) {
				  tmp = ary[i];
				  ary[i] = ary[i+1];
				  ary[i+1] = tmp;
			  }
		  }*/

	  //difference
	  double ary3[10][10];

	  for (i = 0; i < N; i++) {
		  for (j = 0; j < N; j++) {
			  ary3[i][j] = ary1[i][j] - ary2[i][j];
		  }
	  }

	  //ファイル(save.csv)に書き込む
	  FILE* fp3; // FILE型構造体
	  errno_t err3; // errno_t型(int型)
	  
	  char fname3[] = "difresult.csv";

	  err3 = fopen_s(&fp3, fname3, "w"); // ファイルを開く。失敗するとエラーコードを返す。

	  //printf("%lf,%lf,%lf", ary3[0], ary3[1], ary3[2]);
	  //printf("\n");

	  /*if (err2 == NULL) {
		  printf("can not open write file.");
		  //return -1;
	  }*/

	  //if (err2 != NULL) {
		  for (i = 0; i < N; i++) {
			  //fprintf(fp3, "%lf", ary3[i][0]);
				  for (j = 1; j < N; j++) {
					  //カンマで区切ることでCSVファイルとする
					  fprintf(fp3, "%lf", ary3[j][i]);
					  fprintf(fp3, ",");
				  }
				  fprintf(fp3, "\n");
		  }

		  printf("check\n");
		  //printf("%lf,%lf,%lf",ary3[0],ary3[1],ary3[2]);

		  fclose(fp3);

		  printf("end\n");
	  //}

	  //int a[3] = {0,1,2};

	  /*int i;
	  i = fun(1) & fun(0);
	  cout << i;*/

	  /*int n = 1;
	  s(n);
	  cout << s(n);*/

	  //complex c1;
	  //c1 = 3.0;
	  //c1.print();

	/*CBinaryFile  bin;
	CFile* pFile = dynamic_cast<CFile*>(&bin); //dynamic cast:継承関係のチェック　不当なキャストの場合はNULLを返す　使用するにはランタイムタイム情報が必要
	CTextFile* pText = dynamic_cast<CTextFile*>(pFile);
	CBinaryFile* pBin = dynamic_cast<CBinaryFile*>(pFile);*/
	
	//First FirstObject;
	//FirstObject.Print(); 
	//FirstObject.~First();

	//offsetof(SPerson, nBirthmonth); //nBirthmonth の SPerson の先頭からの位置を取得

	/*const int x = 20;
	const int* ptr;
	ptr = &x;
	//*ptr = 10;
	cout << *ptr;*/

	/*int i = 0;

	do {
		i++;
		if (i == 3)
			break;
		cout << i;
	   }

	while (i < 5);*/

	//:: (スコープ・レゾリューション)演算子は、隠された名前を修飾して、 それらの名前を引き続き使用できるようにするために使われます。 
	//   ブロックまたはクラス内の同じ名前の明示宣言によって、 ネーム・スペース名またはグローバル・スコープ名が隠されている場合は、単項スコープ演算子を使用できます。
	//::count = 1; set global count to 1

	/*A ob1; //オブジェクトの作成
	B ob2;
	C ob3;
	A* obj;
	B* obj2;

	obj = &ob1;
	obj->Print();
	obj = &ob2;
	obj->Print();
	obj = &ob3;
	obj->Print();

	obj2 = &ob2;
	obj2->Print();
	obj2 = &ob2;
	obj2->Print();
	obj2 = &ob3;
	obj2->Print();*/

	/*CFile* pfile;

	  pfile = new CBinaryFile;
	  if (pfile == NULL)
		  return 0;
	  Write(pfile);
	  delete pfile;

	  pfile = new CTextFile;
	  if (pfile == NULL)
		  return 0;
	  Read(pfile);
	  delete pfile;*/

	  /*complex c1, c2;

	  if (c1 == c2)
		  cout << "OK";
	  else {
		  cout << "ERROR";
			}*/

	 /* B sc[2];
	  B *bc = (B*) sc;

	  for (int i = 0; i < 2; i++)
		  (bc++)->print();*/

	  /*A obj3;
	  obj3.Print();*/

	  /*SampleClass *obj;
	  obj = new SampleClass("Test");
	  obj->Print();*/

	  /*B b, *ob;
	  ob = &b;
	  ob->age = 10;

	  ob->Print();*/

	  /*enum state { ok, error, warning };
	  enum state s1, s2, s3, s4;

	  s1 = ok;
	  s2 = warning;
	  s3 = error;
	  s4 = ok;

	  cout << s1 << s2 << s3 << s4;*/

	  /*union un
	  {
		  int x;
		  char c;
	  };

	  union un u1 = { 10 };
	  union un u2 = { 'a' };
	  union un u3 = { 20};

	  cout << u1.x;
	  cout << u2.c;
	  cout << u3.x;*/

	  /*First ob1, *ob2;
	  ob2 = new First();
	  First* t;

	  t = &ob1;
	  t->setName();
	  t->Print();

	  t = ob2;
	  t->setName("Steve");
	  ob2->Print();*/	

	  //int c = 'b';
	  //cout << c << flush;

	  //DEBUG_START();

	  /*int anTest[] = {
		  41, 100, 87, 43, 56, 78, 12, 98, 56, 67,
	  };

	  cout << "平均点は " << Average(anTest, 10) << " 点です。" << endl;*/

	  //DEBUG_END();

	  //char s1[] = "Hello";
	  //char s2[] = "world";
	  //char*  ptr = s1;

	  //*ptr = 'a';
	  //ptr = s2;

	  //cout << ptr << ' ';

	  /*int c;
	  A obj;

	  obj.i = 5;
	  cin >> c;

	  try
	  {
		  switch (c)
		  {
		  case 1: throw 20;
		  case 2: throw 5.2f;
		  case 3: throw obj;
		  default: cout << "No exception";
		  }
	  }
	  catch (int e)
	  {
		  cout << "int exception. Exception Nr. " << e;
	  }
	  catch (A e)
	  {
		  cout << "object exception. Exception Nr. " << e.i;
	  }
	  catch (...)
	  {
		  cout << "An exception occurred.";
	  }*/

	  /*int i, j;
	  for (i = 0, j = 1; j < 2, i < 4; i++, j++);

	  cout << i << " " << j; return 0;*/

	  //B b1;
	  //C c1;

	  //const int x = 1;
	  //int const* y = &x;
	  //const int* y = &x;
	  //cout << *y;

	  /*B ob2;
	  C ob3;
	  A* obj;

	  obj = &ob2;
	  obj->Print();
	  obj = &ob3;
	  obj->Print();*/

	  //int a[2] = {1,2};
	  //print(a[1]);

	  //int a = 0;
	  //fun(a);

	  /*int a;
	  a = 3;
	  cout << s(a);*/

	  //complex c1, c2, c3;
	  //c3 = c1 + c2;
	  //c3.Print();

	  /*float a, b, *f;
	  a = 1.5; b = 3.4;
	  f = sum(a, b);
	  cout << *f;*/

	  //int b = 1;
	  //Disp(b);

	  //void* p;
	  //char  str[100];
	  //int   num;

	  //p = Max<void*>(str, &num); //テンプレート実引数
	  //cout << "より大きいアドレスは "<< p << " です。" << endl;

	  /*CTextFile txt;
	  txt.Open("Test.txt", "w");
	  if (txt.IsValid() == false)
		  return 0;

	  txt.WriteString("He sang, \"まったり　まったり　まったりな～♪\"");
	  txt.Close();

	  CBinaryFile bin;
	  bin.Open("Test.txt", "r");
	  if (bin.IsValid() == false)
		  return 0;

	  const int READLENGTH = 16;
	  char bufHex[READLENGTH * 3 + 1];
	  char bufASCII[READLENGTH + 1];
	  int nRead;

	  do
	  {
		  nRead = bin.ReadAndDump(bufHex, bufASCII, READLENGTH);
		  cout << bufHex << bufASCII << endl;
	  } 
	  
	  while (nRead == READLENGTH);

	  CFile     bin;
	  CTextFile txt;

	  Viss(1);
	  bin.Open("Test.txt", "r");
	  Viss(2);
	  txt.Open("Test.txt", "r");
	  Viss(3);*/

	  /*CFile     bin;
	  CTextFile txt;

	  if (Open(txt, "w") == false)
		  return 0;
	  Write(txt);
	  txt.Close();

	  if (Open(bin, "r") == false)
		  return 0;
	  Load(bin);
	  bin.Close();*/
	  
	  /*CFile     bin;
	  CTextFile txt;
	  char      buffer[128];
	  int       nRead;

	  if (txt.Open("Test.txt", "w") == false)
		  return 0;
	  printf("check\n");

	  printf("check\n");
	  txt.Write("12345",30);
	  txt.Close();

	  if (bin.Open("Test.txt", "r") == false)
		  return 0;

	  nRead = bin.Read(buffer, sizeof buffer - 1);
	  buffer[nRead] = 0;
	  cout << buffer << endl;*/

	  /*int i;

	  InitRand();

	  for (i = 0; i < 20; i++)
		  cout << Dice() + Dice() << ' ';*/

	  //cout << flush;

	  /*int* p;

	  p = new int;

	  if (p == NULL)
		  return 0;


	  *p = 0;

	  cout << *p << endl;

	  delete p;*/

	  /*extern int a;

	  Func();

	  a = 5;
	  Func();*/

	  /*cout << a << " : " << &a << endl;

	  int a = 2;
	  cout << a << " : " << &a << endl;

	  {
		  int a = 3;
		  cout << a << " : " << &a << endl;
	  }

	  cout << ::a << " : " << &::a << endl;*/

	  /*AddressCheck();
	  InitOnceCheck();
	  ZeroInitCheck();
	  HoldValueCheck();*/

	/*SStudent students[] = {
		{ "赤井孝",   73, 98, 86 },
		{ "笠井大介", 64, 45, 40 },
		{ "吉田叶",   76, 78, 69 },
	  };

	  for (int i = 0; i < ELEM(students); i++)
		  Disp(&students[i]);*/
	  
	  /*FILE* pFile;
	  FILE* pFile1;
	  errno_t error,error1;
	  char buffer[256];*/

	  /*error = fopen_s(&pFile,"text1.txt", "w");
	  fputs("ファイルに書き込みます", pFile);

	  if (fopen_s(&pFile, "text.txt1", "w") != 0)
		  printf("ファイルを作成できません");

	  fclose(pFile);*/

	  /*error1 = fopen_s(&pFile1, "text.txt", "r");
	  fgets(buffer,256,pFile1);
	  printf(buffer);
	  if (fopen_s(&pFile1, "text.txt", "r") != 0)
		  printf("ファイルを開けません");

	  fclose(pFile1);*/

	  /*FILE* pFile;
	  char  buffer[512];
	  int   i;
	  int nLength;
	  int temp;
	  errno_t error;*/

	  /*printf("何か文字列を入力して下さい");

	  scanf_s("%31s",buffer,512);

	  //fgets(buffer, 512, pFile);

	  error = fopen_s(&pFile,"text2.txt", "w");

	  //if (fopen_s(&pFile, "text2.txt", "w") != 0)
		  //printf("ファイルを作成できません");

	  fprintf(pFile, "%d\n" ,strlen(buffer));

	  for (i = 0; buffer[i]; i++)
	    fprintf(pFile, "%02X ", (unsigned char)buffer[i]);

	  fclose(pFile);*/

	  /*error = fopen_s(&pFile,"text2.txt", "r");

	  if (pFile == NULL)
		  printf("ファイルを読み込めません");
		  //return 0;

	  fscanf_s(pFile, "%d", &nLength);

	  printf("文字列の長さは %d バイトです。\n", nLength);

	  for (i = 0; i < nLength; i++)
	  {
		  fscanf_s(pFile, "%x", &temp);
		  putchar(temp);
	  }

	  fclose(pFile);*/

	  /*FILE* pFile;
	  char buffer[256];
	  int nLength;
	  errno_t error;

	  /*printf("何か文字列を入力してください");
	  scanf_s("%31s", buffer, 256);

	  error = fopen_s(&pFile, "fwrite.txt", "wb");

	  nLength = strlen(buffer);
	  //fwrite(&nLength, 4, 1, pFile);
	  fwrite(buffer, 1, nLength + 1, pFile);

	  fclose(pFile);

	  error = fopen_s(&pFile,"fwrite.txt", "rb");
	  //if (pFile == NULL)
		//  return 0;

	  //buffer[255] = 0;

	  //fread(&nLength, 4, 1, pFile);
	  fread(buffer, 1, 256, pFile);

	  printf(buffer);

	  fclose(pFile);*/

	  /*int nFibo[10];

	  StoreFibo(nFibo, ELEM(nFibo));
	  DispFibo(nFibo, ELEM(nFibo));*/

	  return 0;
  }

 // void fun(int n) 
 //{ if (n < 4) { fun(++n); cout << n <<endl; } }

  /*int s(int n)
  {
	  if (n == 0) return 1;
	  //return s(n >0 ? 1:1) * n;
  }*/