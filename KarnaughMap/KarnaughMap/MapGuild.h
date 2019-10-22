#pragma once

#define MAX 8

/*
Class này có chức năng chính là tạo ra một cái map đánh số ô hỗ trợ người dùng cho input đầu vào
*/

class MapGuild
{
private:
	// Lấy hàng và cột tương ứng với số lượng biến Karr đầu vào
	int c_row;
	int c_col;

	// Số biến của biểu đồ Karr
	int num_var;

	// Map guild
	int c_map[MAX][MAX];



public:
	// Init map ban đầu:
	void set_Map();

	// Constructor:
	MapGuild(int num_var);

	// Method:
	void show();				// Showmap
	void update(int in);		// Update mỗi lần có giá trị nhập vào
};

