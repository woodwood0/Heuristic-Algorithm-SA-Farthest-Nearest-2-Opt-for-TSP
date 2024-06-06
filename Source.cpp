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
	vector<bool> check(num + 1);		//�T�{�O�_�b���j��
	vector<double> dist(num + 1);		//�U�I�����j��̪�Z��
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	int a = 1;							//�i�J�j�馸��
	int head = 0;						//�����Q�������j���Y
	int tail = 0;						//�����Q�������j���
	for (int i = 1; i <= num; i++)
	{
		check[i] = 0;
		inext[i] = 0;
		dist[i] = ddarray[1][i];
	}

	check[1] = 1;//�q�Ĥ@�I�}�l
	inext[1] = 1;

	do
	{
		a++;

		for (int i = 1; i <= num; i++)//��n�[�i�Ӫ��I
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
		for (int i = 1; i <= num; i++)//��̻ܳ����I���J
		{
			if (dist[i] > tmp_d && dist[i] != 0)
			{
				tmp_d = dist[i];
				tmp_n = i;
			}
		}
		check[tmp_n] = 1;

		tmp_d2 = 1000000;
		for (int i = 1; i <= num; i++)//��ܼW�[�Z���̤֪��[�J
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

		//���J
		inext[tmp_n] = head;
		inext[tail] = tmp_n;
	} while (a <= num - 1);

	cout << "Farthest Insertion ��l���|��:" << endl;//���|��X
	int path = 1;
	cout << 1;
	for (int i = 1; i <= num; i++)
	{
		cout << "��" << inext[path];
		path = inext[path];
	}
	cout << endl;

	for (int i = 1; i <= num; i++)//��X�Z��
	{
		if (inext[i] != 0)//delete
		{
			L = L + ddarray[i][inext[i]];
		}
	}
	cout << "���|����:" << L << endl;
	cout << endl;
}

void near_insert(vector<vector<int> >array, vector<vector<double> >ddarray, int num)
{
	vector<bool> check(num + 1);		//�T�{�O�_�b���j��
	vector<double> dist(num + 1);		//�U�I�����j��̪�Z��
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	double L = 0;						//�`����
	int a = 1;							//�i�J�j�馸��
	int head = 0;						//�����Q�������j���Y
	int tail = 0;						//�����Q�������j���
	for (int i = 1; i <= num; i++)
	{
		check[i] = 0;
		inext[i] = 0;
		dist[i] = ddarray[1][i];
	}

	check[1] = 1;//�q�Ĥ@�I�}�l
	inext[1] = 1;

	do
	{
		a++;

		for (int i = 1; i <= num; i++)//��n�[�i�Ӫ��I
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
		for (int i = 1; i <= num; i++)//��̪ܳ��I���J
		{
			if (dist[i] < tmp_d && dist[i] != 0)
			{
				tmp_d = dist[i];
				tmp_n = i;
			}
		}
		check[tmp_n] = 1;

		tmp_d2 = 1000000;
		for (int i = 1; i <= num; i++)//��ܼW�[�Z���̤֪��[�J
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

		//���J
		inext[tmp_n] = head;
		inext[tail] = tmp_n;
	} while (a <= num - 1);

	cout << "Nearest Insertion ��l���|��:" << endl;//���|��X
	int path = 1;
	cout << 1;
	for (int i = 1; i <= num; i++)
	{
		cout << "��" << inext[path];
		path = inext[path];
	}
	cout << endl;

	for (int i = 1; i <= num; i++)//��X�Z��
	{
		if (inext[i] != 0)//delete
		{
			L = L + ddarray[i][inext[i]];
		}
	}
	cout << "���|����:" << L << endl;
	cout << endl;
}

void opt2(vector<int> H, vector<vector<double> >ddarray, int num,
	int sh, int st, int b, double maxd, double od, double nd)
{
	do
	{
		b++;   //����
		maxd = 100000;   //�C�����n���m
		//�H�U����ڭn�洫
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
						ddarray[H[i]][H[i + 1]] - ddarray[H[j]][H[j + 1]];   //�s-��			
				}
			}
		}
		if (maxd >= 0)
		{
			break;
		}

		od = 0;   //�¶Z���p�⭫�m
		for (int i = 1; i <= num; i++)//�p���¶Z��
		{
			od += ddarray[H[i]][H[i + 1]];
		}

		//�`�I�`�u�洫
		for (int i = 0; i <= ((st - sh) / 2 - 0.5); i++)
		{
			int tmp_s;
			tmp_s = H[sh + i + 1];
			H[sh + 1 + i] = H[st - i];
			H[st - i] = tmp_s;
		}
		//�p��s�Z��
		nd = 0;  //�s�Z���C�^�X���m
		for (int i = 1; i <= num; i++)
		{
			nd += ddarray[H[i]][H[i + 1]];
		}//cout << nd << endl;
	} while (maxd < 0 && od > nd);


	//��X�̲׵��G
	cout << H[1];
	for (int i = 2; i <= num + 1; i++)
	{
		cout << "��" << H[i];
	}cout << endl;

	cout << "�s�����|��:" << nd << endl;
	cout << "��s" << b - 1 << "��" << endl;
}

void SA(vector<int> S, vector<vector<double> >ddarray, int num, double L)
{
	vector<int> tmp_S;
	int startT = 4000;//��l�ū�
	double endT = 1e-8;//�����ū�
	double delta = 0.999;//�ū��ܤƲv
	int limit = 10000;//���v��ܤW��,��ܤw�g������u��
	srand((int)(time(NULL)));


	do
	{
		tmp_S = S;
		int tmp_d = 0;
		int P_L = 0;//�H�@�w���v�������� 

		int x = rand() % (num - 1) + 2;
		int y = rand() % (num - 1) + 2;

		while (x == y)//�����H�����ͨ�Ӥ������I 
		{
			x = rand() % (num - 1) + 2;
			y = rand() % (num - 1) + 2;
		}

		swap(tmp_S[x], tmp_S[y]);//�b����|�W�H���洫��Ӥ������I�o��s���|

		for (int i = 1; i <= num; i++)
		{
			tmp_d += ddarray[tmp_S[i]][tmp_S[i + 1]];
		}

		//����s�¸��|
		double dE = tmp_d - L;
		if (dE < 0)
		{
			S = tmp_S;
			L = tmp_d;
		}
		else
		{
			double rd = rand() / (RAND_MAX + 1.0);//�H�����ͷ��v�G0~1
			if (exp(-dE * 10000 / startT) > rd)
			{
				S = tmp_S;
				L = tmp_d;
				P_L++;
			}
		}
		if (P_L == limit) break;//�F�쭭��A�����h�X 
		startT *= delta;//�ū��ܤơA���C 

	} while (startT > endT);


	//���|��X
	cout << S[1];
	for (int i = 2; i <= num + 1; i++)
	{
		cout << "��" << S[i];
	}cout << endl;

	cout << "���|����:" << L << endl;
	cout << endl;
}

int main(void)
{
	int num = 0;
	cout << "�п�J�ɦW: ______.txt" << endl;
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
		cout << "�L�kŪ�J�ɮ�\n";
		system("pause");
		return 0;
	}

	string line;						//Ū�Ĥ@��
	getline(inf, line);
	int first = line.find(':');
	string substr = line.substr(first + 2);
	num = atoi(substr.c_str());
	cout << "num = " << num << endl;

	getline(inf, line);                 //Ū�ĤG��

	vector<vector<int> >
		array(num + 1, vector<int>(3 + 1)); //Ū�ĤT��H��
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			inf >> array[i][j];
		}
	}
	inf.close();

	distance(array, num);				//�p��U�I�������Z��

	srand(time(NULL));
	double START1, START2, END1, END2;

	far_insert(array, ddarray, num);
	cout << "SA �ﵽ Farthest Insertion���|��:" << endl;
	vector<int> S(num + 2);  //�s���|
	S[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		S[i] = inext[S[i - 1]];
	}
	START1 = clock();
	SA(S, ddarray, num, L);
	END1 = clock();
	cout << endl << "�{������Ҫ�O:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "�i��B��Ҫ�O���ɶ�:" << (END1 - START1) / CLOCKS_PER_SEC << " S"
		<< endl << endl << endl;

	near_insert(array, ddarray, num);
	cout << "SA �ﵽ Nearest Insertion���|��:" << endl;
	S[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		S[i] = inext[S[i - 1]];
	}
	START2 = clock();
	SA(S, ddarray, num, L);
	END2 = clock();
	cout << endl << "�{������Ҫ�O:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "�i��B��Ҫ�O���ɶ�:" << (END2 - START2) / CLOCKS_PER_SEC << " S"
		<< endl << endl;
	/*
	vector<bool> check(num + 1);		//�T�{�O�_�b���j��
	vector<double> dist(num + 1);		//�U�I�����j��̪�Z��
	int tmp_n = 0;
	double tmp_d = 0;
	double tmp_d2 = 1000000;
	double L = 0;						//�`����
	int a = 1;							//�i�J�j�馸��
	int head = 0;						//�����Q�������j���Y
	int tail = 0;						//�����Q�������j���

	double maxd = 100000;
	int sh = 0;  //�洫���Ĥ@�ڸ`�u�Y
	int st = 0;  //�洫���ĤG�ڸ`�u�Y
	int b = 0;   //�p�⦸��
	double od = 0;   //�p���ª��Z��
	double nd = 0;   //�p��s���Z��


	START1 = clock();
	far_insert(array, ddarray, num, check,  dist,
		tmp_n, tmp_d, tmp_d2, L, a, head, tail);
	cout << "2_opt �ﵽ Farthest Insertion���|��:" << endl;
	vector<int> H(num + 2);  //�s���|
	H[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		H[i] = inext[H[i - 1]];
	}
	opt2(H, ddarray, num, sh, st, b, maxd, od, nd);
	END1 = clock();

	cout << endl << "�{������Ҫ�O:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "�i��B��Ҫ�O���ɶ�:" << (END1 - START1) / CLOCKS_PER_SEC << " S"
		<< endl << endl << endl;

	START2 = clock();
	near_insert(array, ddarray, num, check, dist,
		tmp_n, tmp_d, tmp_d2, L, a, head, tail);
	cout << "2_opt �ﵽ Nearest Insertion���|��:" << endl;
	H[1] = 1;
	for (int i = 2; i <= num + 1; i++)
	{
		H[i] = inext[H[i - 1]];
	}
	opt2(H, ddarray, num, sh, st, b, maxd, od, nd);
	END2 = clock();

	cout << endl << "�{������Ҫ�O:" << (double)clock() / CLOCKS_PER_SEC << " S";
	cout << endl << "�i��B��Ҫ�O���ɶ�:" << (END2 - START2) / CLOCKS_PER_SEC << " S"
		<< endl << endl;
		*/
	system("pause");
	return 0;
}