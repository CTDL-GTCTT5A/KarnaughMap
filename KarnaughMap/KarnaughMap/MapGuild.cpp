#include "MapGuild.h"
#include<iostream>
#include<iomanip>
using namespace std;

/*
Set map Init ban đầu ứng với số lượng biến của biểu đồ Karr
Đầu ra là một matrix đánh số
*/ 
void MapGuild::set_Map()
{
	switch (this->num_var)
	{
	case 2: {
		c_map[0][0] = 0;	c_map[0][1] = 1;	c_map[1][0] = 2;	c_map[1][1] = 3;
		break;
	}
	case 3: {
		c_map[0][0] = 0;	c_map[0][1] = 1;	c_map[0][2] = 3;	c_map[0][3] = 2;
		c_map[1][0] = 4;	c_map[1][1] = 5;	c_map[1][2] = 7;	c_map[1][3] = 6;
		break;
	}
	case 4: {
		c_map[0][0] = 0;	c_map[0][1] = 1;	c_map[0][2] = 3;	c_map[0][3] = 2;
		c_map[1][0] = 4;	c_map[1][1] = 5;	c_map[1][2] = 7;	c_map[1][3] = 6;
		c_map[2][0] = 12;	c_map[2][1] = 13;	c_map[2][2] = 15;	c_map[2][3] = 14;
		c_map[3][0] = 8;	c_map[3][1] = 9;	c_map[3][2] = 11;	c_map[3][3] = 10;
		break;
	}
	case 5: {
		c_map[0][0] = 0;	c_map[0][1] = 1;	c_map[0][2] = 3;	c_map[0][3] = 2;	c_map[0][4] = 6;	c_map[0][5] = 7;	c_map[0][6] = 5;	c_map[0][7] = 4;
		c_map[1][0] = 8;	c_map[1][1] = 9;	c_map[1][2] = 11;	c_map[1][3] = 10;	c_map[1][4] = 14;	c_map[1][5] = 15;	c_map[1][6] = 13;	c_map[1][7] = 12;
		c_map[2][0] = 24;	c_map[2][1] = 25;	c_map[2][2] = 27;	c_map[2][3] = 26;	c_map[2][4] = 30;	c_map[2][5] = 31;	c_map[2][6] = 29;	c_map[2][7] = 28;
		c_map[3][0] = 16;	c_map[3][1] = 17;	c_map[3][2] = 19;	c_map[3][3] = 18;	c_map[3][4] = 22;	c_map[3][5] = 23;	c_map[3][6] = 21;	c_map[3][7] = 20;
		break;
	}
	case 6: {
		c_map[0][0] = 0;	c_map[0][1] = 1;	c_map[0][2] = 3;	c_map[0][3] = 2;	c_map[0][4] = 6;	c_map[0][5] = 7;	c_map[0][6] = 5;	c_map[0][7] = 4;
		c_map[1][0] = 8;	c_map[1][1] = 9;	c_map[1][2] = 11;	c_map[1][3] = 10;	c_map[1][4] = 14;	c_map[1][5] = 15;	c_map[1][6] = 13;	c_map[1][7] = 12;
		c_map[2][0] = 24;	c_map[2][1] = 25;	c_map[2][2] = 27;	c_map[2][3] = 26;	c_map[2][4] = 30;	c_map[2][5] = 31;	c_map[2][6] = 29;	c_map[2][7] = 28;
		c_map[3][0] = 16;	c_map[3][1] = 17;	c_map[3][2] = 19;	c_map[3][3] = 18;	c_map[3][4] = 22;	c_map[3][5] = 23;	c_map[3][6] = 21;	c_map[3][7] = 20;
		c_map[4][0] = 48;	c_map[4][1] = 49;	c_map[4][2] = 51;	c_map[4][3] = 50;	c_map[4][4] = 54;	c_map[4][5] = 55;	c_map[4][6] = 53;	c_map[4][7] = 52;
		c_map[5][0] = 56;	c_map[5][1] = 57;	c_map[5][2] = 59;	c_map[5][3] = 58;	c_map[5][4] = 62;	c_map[5][5] = 63;	c_map[5][6] = 61;	c_map[5][7] = 60;
		c_map[6][0] = 40;	c_map[6][1] = 41;	c_map[6][2] = 43;	c_map[6][3] = 42;	c_map[6][4] = 46;	c_map[6][5] = 47;	c_map[6][6] = 45;	c_map[6][7] = 44;
		c_map[7][0] = 32;	c_map[7][1] = 33;	c_map[7][2] = 35;	c_map[7][3] = 34;	c_map[7][4] = 38;	c_map[7][5] = 39;	c_map[7][6] = 37;	c_map[7][7] = 36;
		break;
	}
	}
}

// Constructor:
MapGuild::MapGuild(int num_var)
{
	this->num_var = num_var;

	switch (num_var)
	{
	case 2: {
		this->c_row = 2;
		this->c_col = 2;

		break;
	}
	case 3: {
		this->c_row = 2;
		this->c_col = 4;

		break;
	}
	case 4: {
		this->c_row = 4;
		this->c_col = 4;

		break;
	}
	case 5: {
		this->c_row = 4;
		this->c_col = 8;

		break;
	}
	case 6: {
		this->c_row = 8;
		this->c_col = 8;

		break;
	}
	default:
		cout << "Error number of variable ! " << endl;
		break;
	}
}

/*
Đầu ra là matrix với các ô đã được chọn sẽ đưuọc gán thành giá trị -1
*/
void MapGuild::show()
{
	this->num_var = num_var;

	switch (num_var)
	{
	case 2: {
		string emt[2] = { " 0"," 1" };

		cout << setw(3) << "  0" << "  ";
		cout << setw(3) << "  1" << "  " << endl;
		cout << "_________" << endl;

		for (size_t i = 0; i < this->c_row; i++)
		{
			for (size_t j = 0; j < this->c_col; j++)
			{
				cout << setw(3) << this->c_map[i][j] << " |";
			}
			cout << "   " << emt[i];
			cout << endl;
		}

		break;
	}
	case 3: {
		string emt[2] = { " 0"," 1" };

		cout << setw(3) << " 00" << "  ";
		cout << setw(3) << " 01" << "  ";
		cout << setw(3) << " 11" << "  ";
		cout << setw(3) << " 10" << "  " << endl;
		cout << "___________________" << endl;

		for (size_t i = 0; i < this->c_row; i++)
		{
			for (size_t j = 0; j < this->c_col; j++)
			{
				cout << setw(3) << this->c_map[i][j] << " |";
			}
			cout << "   " << emt[i];
			cout << endl;
		}

		break;
	}
	case 4: {
		string emt[4] = { "00","01","11","10" };

		cout << setw(3) << " 00" << "  ";
		cout << setw(3) << " 01" << "  ";
		cout << setw(3) << " 11" << "  ";
		cout << setw(3) << " 10" << "  " << endl;
		cout << "___________________" << endl;

		for (size_t i = 0; i < this->c_row; i++)
		{
			for (size_t j = 0; j < this->c_col; j++)
			{
				cout << setw(3) << this->c_map[i][j] << " |";
			}
			cout << "   " << emt[i];
			cout << endl;
		}

		break;

	}
	case 5: {
		string emt[4] = { "00","01","11","10" };

		cout << setw(3) << "000" << "  ";
		cout << setw(3) << "001" << "  ";
		cout << setw(3) << "011" << "  ";
		cout << setw(3) << "010" << "  ";
		cout << setw(3) << "110" << "  ";
		cout << setw(3) << "111" << "  ";
		cout << setw(3) << "101" << "  ";
		cout << setw(3) << "100" << "  " << endl;
		cout << "_______________________________________" << endl;

		for (size_t i = 0; i < this->c_row; i++)
		{
			for (size_t j = 0; j < this->c_col; j++)
			{
				cout << setw(3) << this->c_map[i][j] << " |";
			}
			cout << "   " << emt[i];
			cout << endl;
		}

		break;
	}
	case 6: {
		string emt[8] = { "000","001","011","010","110","111","101","100" };

		cout << setw(3) << "000" << "  ";
		cout << setw(3) << "001" << "  ";
		cout << setw(3) << "011" << "  ";
		cout << setw(3) << "010" << "  ";
		cout << setw(3) << "110" << "  ";
		cout << setw(3) << "111" << "  ";
		cout << setw(3) << "101" << "  ";
		cout << setw(3) << "100" << "  " << endl;
		cout << "_______________________________________" << endl;

		for (size_t i = 0; i < this->c_row; i++)
		{
			for (size_t j = 0; j < this->c_col; j++)
			{
				cout << setw(3) << this->c_map[i][j] << " |";
			}
			cout << "   " << emt[i];
			cout << endl;
		}

		break;
	}
	}
}

/*
Với giá trị in người dùng đặt vào. Ta sẽ thay ô nào trong matrix có giá trị in thành -1
*/
void MapGuild::update(int in)
{
	for (size_t i = 0; i < this->c_row; i++)
	{
		for (size_t j = 0; j < this->c_col; j++)
		{
			if (this->c_map[i][j] == in) {
				this->c_map[i][j] = -1;
				break;
			}
		}
	}
}
