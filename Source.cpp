#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cmath>
#include <time.h>
#include <list>
#include <string>
#include <vector>
using namespace std;

extern vector<vector<double> >ddarray(1003, vector<double>(1003));
void distance(vector<vector<int> >array, int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			ddarray[i][j] = sqrt(pow((array[i][2] - array[j][2]), 2)
				+ pow(array[i][3] - array[j][3], 2));
		}
	}
}

extern vector<int> inext(1003);
static double L = 0;
void far_insert(vector<vector<int> >array, vector<vector<double> >ddarray, int num)
{
	vector<bool> check(num + 1);		//確認是否在次迴圈
	vector<double> dist(num + 1);		//各點離次迴圈最近距離
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	int a = 1;							//進入迴圈次數
	int head = 0;						//紀錄被插的次迴圈頭
	int tail = 0;						//紀錄被插的次迴圈尾
	for (int i = 1; i <= num; i++)
	{
		check[i] = 0;
		inext[i] = 0;
		dist[i] = ddarray[1][i];
	}

	check[1] = 1;//從第一點開始
	inext[1] = 1;

	do
	{
		a++;

		for (int i = 1; i <= num; i++)//選要加進來的點
		{
			if (check[i] == 1)
			{
				for (int k = 1; k <= num; k++)
				{
					if (ddarray[i][k] < dist[k])
					{
						dist[k] = ddarray[i][k];
					}
				}
			}
		}

		tmp_d = 0;
		for (int i = 1; i <= num; i++)//選擇最遠的點插入
		{
			if (dist[i] > tmp_d && dist[i] != 0)
			{
				tmp_d = dist[i];
				tmp_n = i;
			}
		}
		check[tmp_n] = 1;

		tmp_d2 = 1000000;
		for (int i = 1; i <= num; i++)//選擇增加距離最少的加入
		{
			if (i != tmp_n)
			{
				if (check[inext[i]] != 0 && check[i] != 0)
				{
					if (ddarray[i][tmp_n] + ddarray[tmp_n][inext[i]] - ddarray[i][inext[i]] < tmp_d2)
					{
						tmp_d2 = ddarray[i][tmp_n] + ddarray[tmp_n][inext[i]] - ddarray[i][inext[i]];
						head = inext[i];
						tail = i;
					}
				}
			}
		}

		//插入
		inext[tmp_n] = head;
		inext[tail] = tmp_n;
	} while (a <= num - 1);

	cout << "Farthest Insertion 初始路徑為:" << endl;//路徑輸出
	int path = 1;
	cout << 1;
	for (int i = 1; i <= num; i++)
	{
		cout << "→" << inext[path];
		path = inext[path];
	}
	cout << endl;

	for (int i = 1; i <= num; i++)//輸出距離
	{
		if (inext[i] != 0)//delete
		{
			L = L + ddarray[i][inext[i]];
		}
	}
	cout << "路徑長為:" << L << endl;
	cout << endl;
}

void near_insert(vector<vector<int> >array, vector<vector<double> >ddarray, int num)
{
	vector<bool> check(num + 1);		//確認是否在次迴圈
	vector<double> dist(num + 1);		//各點離次迴圈最近距離
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	double L = 0;						//總長度
	int a = 1;							//進入迴圈次數
	int head = 0;						//紀錄被插的次迴圈頭
	int tail = 0;						//紀錄被插的次迴圈尾
	for (int i = 1; i <= num; i++)
	{
		check[i] = 0;
		inext[i] = 0;
		dist[i] = ddarray[1][i];
	}

	check[1] = 1;//從第一點開始
	inext[1] = 1;

	do
	{
		a++;

		for (int i = 1; i <= num; i++)//選要加進來的點
		{
			if (check[i] == 1)
			{
				for (int k = 1; k <= num; k++)
				{
					if (ddarray[i][k] < dist[k])
					{
						dist[k] = ddarray[i][k];
					}
				}
			}
		}

		tmp_d = 1000000;
		for (int i = 1; i <= num; i++)//選擇最近的點插入
		{
			if (dist[i] < tmp_d && dist[i] != 0)
			{
				tmp_d = dist[i];
				tmp_n = i;
			}
		}
		check[tmp_n] = 1;

		tmp_d2 = 1000000;
		for (int i = 1; i <= num; i++)//選擇增加距離最少的加入
		{
			if (i != tmp_n)
			{
				if (check[inext[i]] != 0 && check[i] != 0)
				{
					if (ddarray[i][tmp_n] + ddarray[tmp_n][inext[i]] - ddarray[i][inext[i]] < tmp_d2)
					{
						tmp_d2 = ddarray[i][tmp_n] + ddarray[tmp_n][inext[i]] - ddarray[i][inext[i]];
						head = inext[i];
						tail = i;
					}
				}
			}
		}

		//插入
		inext[tmp_n] = head;
		inext[tail] = tmp_n;
	} while (a <= num - 1);

	cout << "Nearest Insertion 初始路徑為:" << endl;//路徑輸出
	int path = 1;
	cout << 1;
	for (int i = 1; i <= num; i++)
	{
		cout << "→" << inext[path];
		path = inext[path];
	}
	cout << endl;

	for (int i = 1; i <= num; i++)//輸出距離
	{
		if (inext[i] != 0)//delete
		{
			L = L + ddarray[i][inext[i]];
		}
	}
	cout << "路徑長為:" << L << endl;
	cout << endl;
}

void opt2(vector<int> H, vector<vector<double> >ddarray, int num,
	int sh, int st, int b, double maxd, double od, double nd)
{
	do
	{
		b++;   //次數
		maxd = 100000;   //每次都要重置
		//以下找哪根要交換
		for (int i = 1; i <= num - 2; i++)
		{
			for (int j = i + 2; j <= num - 1; j++)
			{
				if (ddarray[H[i]][H[j]] + ddarray[H[i + 1]][H[j + 1]] -
					ddarray[H[i]][H[i + 1]] - ddarray[H[j]][H[j + 1]] < maxd)
				{
					sh = i;
					st = j;
					maxd = ddarray[H[i]][H[j]] + ddarray[H[i + 1]][H[j + 1]] -
						ddarray[H[i]][H[i + 1]] - ddarray[H[j]][H[j + 1]];   //新-舊			
				}
			}
		}
		if (maxd >= 0)
		{
			break;
		}

		od = 0;   //舊距離計算重置
		for (int i = 1; i <= num; i++)//計算舊距離
		{
			od += ddarray[H[i]][H[i + 1]];
		}

		//節點節線交換
		for (int i = 0; i <= ((st - sh) / 2 - 0.5); i++)
		{
			int tmp_s;
			tmp_s = H[sh + i + 1];
			H[sh + 1 + i] = H[st - i];
			H[st - i] = tmp_s;
		}
		//計算新距離
		nd = 0;  //新距離每回合重置
		for (int i = 1; i <= num; i++)
		{
			nd += ddarray[H[i]][H[i + 1]];
		}//cout << nd << endl;
	} while (maxd < 0 && od > nd);


	//輸出最終結果
	cout << H[1];
	for (int i = 2; i <= num + 1; i++)
	{
		cout << "→" << H[i];
	}cout << endl;

	cout << "新的路徑長:" << nd << endl;
	cout << "更新" << b - 1 << "次" << endl;
}

void SA(vector<int> S, vector<vector<double> >ddarray, int num, double L)
{
	vector<int> tmp_S;
	int startT = 4000;//初始溫度
	double endT = 1e-8;//結束溫度
	double delta = 0.999;//溫度變化率
	int limit = 10000;//概率選擇上限,表示已經接近最優解
	srand((int)(time(NULL)));


	do
	{
		tmp_S = S;
		int tmp_d = 0;
		int P_L = 0;//以一定概率接受次數 

		int x = rand() % (num - 1) + 2;
		int y = rand() % (num - 1) + 2;

		while (x == y)//直到隨機產生兩個互異頂點 
		{
			x = rand() % (num - 1) + 2;
			y = rand() % (num - 1) + 2;
		}

		swap(tmp_S[x], tmp_S[y]);//在原路徑上隨機交換兩個互異頂點得到新路徑

		for (int i = 1; i <= num; i++)
		{
			tmp_d += ddarray[tmp_S[i]][tmp_S[i + 1]];
		}

		//比較新舊路徑
		double dE = tmp_d - L;
		if (dE < 0)
		{
			S = tmp_S;
			L = tmp_d;
		}
		else
		{
			double rd = rand() / (RAND_MAX + 1.0);//隨機產生概率：0~1
			if (exp(-dE * 10000 / startT) > rd)
			{
				S = tmp_S;
				L = tmp_d;
				P_L++;
			}
		}
		if (P_L == limit) break;//達到限制，直接退出 
		startT *= delta;//溫度變化，降低 

	} while (startT > endT);


	//路徑輸出
	cout << S[1];
	for (int i = 2; i <= num + 1; i++)
	{
		cout << "→" << S[i];
	}cout << endl;

	cout << "路徑長為:" << L << endl;
	cout << endl;
}

int main(void)
{
	int num = 0;
	cout << "請輸入檔名: ______.txt" << endl;
	cin >> num;

	ifstream inf;
	if (num == 51) inf.open("51.txt", ios::in);
	if (num == 107) inf.open("107.txt", ios::in);
	if (num == 150) inf.open("150.txt", ios::in);
	if (num == 200) inf.open("200.txt", ios::in);
	if (num == 262) inf.open("262.txt", ios::in);
	if (num == 318) inf.open("318.txt", ios::in);
	if (num == 439) inf.open("439.txt", ios::in);
	if (num == 575) inf.open("575.txt", ios::in);
	if (num == 783) inf.open("783.txt", ios::in);
	if (num == 1002) inf.open("1002.txt", ios::in);
	if (!inf)
	{
		cout << "無法讀入檔案\n";
		system("pause");
		return 0;
	}

	string line;						//讀第一行
	getline(inf, line);
	int first = line.find(':');
	string substr = line.substr(first + 2);
	num = atoi(substr.c_str());
	cout << "num = " << num << endl;

	getline(inf, line);                 //讀第二行

	vector<vector<int> >
		array(num + 1, vector<int>(3 + 1)); //讀第三行以後
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			inf >> array[i][j];
		}
	}
	inf.close();

	distance(array, num);				//計算各點之間的距離

	srand(time(NULL));
	double START1, START2, END1, END2;

	far_insert(array, ddarray, num);
	cout << "SA 改善 Farthest Insertion路徑為:" << endl;
	vector<int> S(num + 2);  //存路徑
	S[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		S[i] = inext[S[i - 1]];
	}
	START1 = clock();
	SA(S, ddarray, num, L);
	END1 = clock();
	cout << endl << "程式執行所花費:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間:" << (END1 - START1) / CLOCKS_PER_SEC << " S"
		<< endl << endl << endl;

	near_insert(array, ddarray, num);
	cout << "SA 改善 Nearest Insertion路徑為:" << endl;
	S[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		S[i] = inext[S[i - 1]];
	}
	START2 = clock();
	SA(S, ddarray, num, L);
	END2 = clock();
	cout << endl << "程式執行所花費:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間:" << (END2 - START2) / CLOCKS_PER_SEC << " S"
		<< endl << endl;
	/*
	vector<bool> check(num + 1);		//確認是否在次迴圈
	vector<double> dist(num + 1);		//各點離次迴圈最近距離
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	double L = 0;						//總長度
	int a = 1;							//進入迴圈次數
	int head = 0;						//紀錄被插的次迴圈頭
	int tail = 0;						//紀錄被插的次迴圈尾

	double maxd = 100000;
	int sh = 0;  //交換的第一根節線頭
	int st = 0;  //交換的第二根節線頭
	int b = 0;   //計算次數
	double od = 0;   //計算舊的距離
	double nd = 0;   //計算新的距離


	START1 = clock();
	far_insert(array, ddarray, num, check,  dist,
		tmp_n, tmp_d, tmp_d2, L, a, head, tail);
	cout << "2_opt 改善 Farthest Insertion路徑為:" << endl;
	vector<int> H(num + 2);  //存路徑
	H[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		H[i] = inext[H[i - 1]];
	}
	opt2(H, ddarray, num, sh, st, b, maxd, od, nd);
	END1 = clock();

	cout << endl << "程式執行所花費:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間:" << (END1 - START1) / CLOCKS_PER_SEC << " S"
		<< endl << endl << endl;

	START2 = clock();
	near_insert(array, ddarray, num, check, dist,
		tmp_n, tmp_d, tmp_d2, L, a, head, tail);
	cout << "2_opt 改善 Nearest Insertion路徑為:" << endl;
	H[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		H[i] = inext[H[i - 1]];
	}
	opt2(H, ddarray, num, sh, st, b, maxd, od, nd);
	END2 = clock();

	cout << endl << "程式執行所花費:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間:" << (END2 - START2) / CLOCKS_PER_SEC << " S"
		<< endl << endl;
		*/
	system("pause");
	return 0;
}