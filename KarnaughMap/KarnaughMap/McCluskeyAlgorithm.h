#pragma once
#include<iostream>
#include<vector>

using namespace std;


class McCluskeyAlgorithm
{
private:
	// Các mảng và phương thức private phục vụ việc tìm tế bào lớn và rút gọn Minimizer
	int num_var;			// Số biến của hàm bool
	int num_cell;			// Số ô đã tô của biểu đồ Kar

	vector<int> input_arr;  // Mảng đầu vào của người dùng
	vector<string> nepi;    // Lưu tế bào lớn [Lọc lấy những tế bào khác nhau trong mảng pi và epi]
	vector<string> pi;      // Mảng lưu các tế bào sau khi đã ghép cặp
	vector<string> epi;     // Lưu tế bào nhỏ (1 ô) hoặc các tế bào không được combine. Dùng để kiểm tra xem nó đã nằm trong tế bào lớn đã ghép cặp hay chưua.
	vector<string> answer;  // Mảng kết quả các tế bào lớn cuối cùng

	int diff_bit(string a, string b, int bit);										  // Đếm số lượng khác nhau của 2 chuổi bit
	vector<string> duplication(vector<string>& a, vector <string>& b);				  // Loại bỏ các phần tử dư thừa trong mảng a (có trong b)
	void combine(vector<string>& combine_mt, vector<string>& binary_mt, int bitnum);  // Kết hợp các dãy bit chênh nhau không quá 1 bit 1 thành các khối tối giản hơn (Ví dụ: -0-1)
	bool isChecked(string pi, string binary, int bit);								  // Kiểm tra các khối không thể kết hợp do lệch nhau hơn 2 bit 1 xem chúng có nằm trong các khối đã được kết hợp rồi hay không (Ví dụ ô 0011 sẽ nằm trong khối -0-1)
	void free_all();


public:
	// Constructor:
	McCluskeyAlgorithm();
	McCluskeyAlgorithm(int num_var);

	// Destructor:
	~McCluskeyAlgorithm();

	void Input();			// Nhập liệu từ người dùng
	void QM_Method();		// Phương thức xữ lý chính: lấy tất cả các tế bào lớn của biểu đồ Kar
	void Minimizer();		// Phương thức rút gọn tế bào lớn lấy công thức đa thức tối tiểu

	void Main_Menu();




};