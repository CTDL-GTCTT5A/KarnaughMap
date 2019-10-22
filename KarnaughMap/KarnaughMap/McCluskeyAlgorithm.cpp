#include "McCluskeyAlgorithm.h"
#include"MapGuild.h"
#include<iostream>
#include<algorithm>

using namespace std;


// Đếm số lượng bit khác nhau của 2 số nguyên truyền vào [đã đổi thành mã nhị phân]
int McCluskeyAlgorithm::diff_bit(string a, string b, int bit)
{
	int diff_bit_num = 0;

	for (int i = 0; i < bit; i++)
	{
		if (a[i] != b[i] && (a[i] != '-' || b[i] != '-'))
			diff_bit_num++;
	}

	return diff_bit_num;
}

// Xóa nhưng phần tử dư thừa trong a [phần tử có cả trong a và b] 
vector<string> McCluskeyAlgorithm::duplication(vector<string>& a, vector<string>& b)
{
	vector<string>::iterator iter;
	vector<string>::iterator iter_b;
	vector<string> c = a;

	for (iter_b = b.begin(); iter_b != b.end(); iter_b++) {
		for (iter = c.begin(); iter != c.end();) {
			if (*iter == *iter_b)
				iter = c.erase(iter);
			else
				iter++;
		}
	}
	return c;
}

// Ghép cặp các chuổi bit chênh lệch nhau ko quá 1 bit 1
void McCluskeyAlgorithm::combine(vector<string>& combine_mt, vector<string>& binary_mt, int bitnum)
{
	vector<string> temp_mt; // Mảng sau khi kết hợp
	vector<string> priv_mt = combine_mt; // Lưu lại mảng combine_minterm trước khi kết hợp

	int size = combine_mt.size();

	// Tạo mảnh đánh dấu để check các vị trí kiểm tra
	vector<int> check(size, 0);
	check.resize(size, 0);

	// Duyệt mảng và tiến hành ghép cặp
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			// Nếu 2 chuổi chỉ khác nhau đúng 1 bit và bit đó ở vị trí tương ứng nhau thì thay vị trí khác đó thành dấu - và nhét chuổi bit đó vào mảng temp_tm
			if (diff_bit(combine_mt[i], combine_mt[j], bitnum) == 1)
			{
				for (int k = 0; k < bitnum; k++)
				{
					if (combine_mt[i][k] != combine_mt[j][k])
					{
						// Đánh dấu đã kết hợp
						check[i] += 1; check[j] += 1;
						string temp = combine_mt[i];
						temp[k] = '-';
						temp_mt.push_back(temp);
						// Đẩy nó vào mảng tem_tm
					}
				}
			}
		}
	}

	// Nếu không thể kết hợp các ô nhỏ thành 1 khối lớn hơn thì return
	if (temp_mt.size() == 0)
		return;

	// Tiến hành sort lại mảng và xóa đi tất cả các phần tử trùng lắp của mảng sau khi kết hợp
	sort(temp_mt.begin(), temp_mt.end());
	// unique() trả về vị trí của các phần tử bị trùng lắp và ta dùng phương thức arase() để xóa nó đi
	temp_mt.erase(unique(temp_mt.begin(), temp_mt.end()), temp_mt.end());

	// Cập nhật lại mảng combine sau mỗi lần kết hợp
	combine_mt = temp_mt;

	// Kiểm tra xem trong quá trình ghép cặp thì các giá trị nào chưa sử dụng thì lưu nó vào mảng pi
	for (int i = 0; i < check.size(); i++)
	{
		if (check[i] == 0)
			pi.push_back(priv_mt[i]);
	}

	check.clear();
}

// Kiểm tra sự kết hợp của 2 chuổi nhị phân
bool McCluskeyAlgorithm::isChecked(string pi, string binary, int bit)
{
	int same_bit_num = 0;
	int count = 0;

	for (int i = 0; i < bit; i++)
	{
		if (pi[i] == '-')
			count++;
	}

	// Nếu vị trí tương ứung bằng nhau chưua được thay thế thì tăng biến đếm lên
	// VÍ dụ pi = -0-1, binary = -011 trả về true. Điều này thể hiện khối -011 nằm trong khối -0-1
	for (int i = 0; i < bit; i++)
	{
		if (pi[i] == binary[i] && (pi[i] != '-'))
			same_bit_num++;
	}

	if ((bit - count) == same_bit_num)
		return true;

	else
		return false;
}

McCluskeyAlgorithm::McCluskeyAlgorithm(int num_var)
{
	this->num_var = num_var;
}

// Phương thức xữ lý chính
void McCluskeyAlgorithm::QM_Method()
{
	int bitnum = this->num_var;  // bitnum: Số lượng biến của  hàm bool
	int num_of_mt = this->input_arr.size(); // number of minterm: Số lượng số ô tô đen

	string s;

	vector<int> check(num_of_mt, 0); // Mảng để kiểm tra các minterm kết hợp với nhau
	vector<int> minterm; // Lưu tạm dữ liệu các số để chuyển sang binary
	vector<int> origin_minterm; // Lưu giá trị các ô input từ người dùng
	vector<string> binary_minterm; // Lưu các giá trị nhị phân từ các oo trong origin_minterm

	for (int i = 0; i < num_of_mt; i++) // Lấy giá trị từ người dùng nhập vào mảng num_of_mt và mảng origin_minterm
	{
		minterm.push_back(input_arr[i]);
		origin_minterm.push_back(input_arr[i]);
	}

	// minterm = origin_minterm

	for (int i = 0; i < num_of_mt; i++) // Duyệt mảng minterm (có num_of_mt phần tử)
	{
		int origin_minterm = minterm[i];

		while (minterm[i] > 1)  // lấy mã nhị phân của các ô mà người dùng nhập vào
		{
			if (minterm[i] % 2 == 1)
				s += '1';
			else
				s += '0';
			minterm[i] /= 2;
		}

		if (origin_minterm == 0)
			s += '0';
		else
			s += '1';

		if (s.size() != bitnum) // Thêm các bit 0 để độ dày chuổi nhị phân bằng với số lượng biến của hàm bool
		{
			while (bitnum != s.size())
			{
				s += '0';
			}
		}
		reverse(s.begin(), s.end()); // Đảo người chuổi nhị phân và đưa vào mảng binary_minterm
		binary_minterm.push_back(s);
		s.clear();
	}

	vector<string> combine_minterm = binary_minterm; // Chép mảng binary_minterm vào mảng combine_minterm và tiến hành combine

	for (int i = 0; i < bitnum; i++)
	{
		// Tiến hành ghép cặp và rút gon:
		// Giả sử sau vòng for đầu (i=0) ta có 2 giá trị -001 và -101 thì vòng for tiếp theo 2 giá trị này có thể gặp nhau và ghép lại thành --01
		// Tiến hành ghép như thế để tạo tế bào lớn

		combine(combine_minterm, binary_minterm, bitnum);
	}

	// lưu lại mảng combine_minterm sau khi ghép cặp xong [gom những phần tử chưua ghép cặp trong comnine và những phần tử đã ghép cặp vào chung mảng pi]
	for (int i = 0; i < combine_minterm.size(); i++)
		pi.push_back(combine_minterm[i]);

	vector<vector<int> > epi_check_board(binary_minterm.size(), vector<int>(pi.size(), 0));

	for (int i = 0; i < binary_minterm.size(); i++)
	{
		for (int j = 0; j < pi.size(); j++)
		{
			/*
			// Kiểm tra nếu thằng còn lại chưau ghép nếu nó đã nằm trong thằng lớn hơn rồi thì gắn nhãn là 1
			// Ví dụ chổ gọi hàm combile thì có 1 hoặc nhiều phần tử trong mảng combine_minterm không thể ghép cặp được do số lượng bit 1 chênh nhau khác 1
			// thì ở bước này ta xét nếu ô đó nằm trong cặp đã kết hợp thì bỏ qua nó.
			// combine_minterm có 3 con 0001, 001-, 011- thì cặp 001- sẽ kết hợp với cặp 011- thành 0-1- và ô 0001 đã nằm trong khối này rồi.
			*/
			if (isChecked(pi[j], binary_minterm[i], bitnum))
				epi_check_board[i][j] = 1;
		}
	}

	for (int i = 0; i < binary_minterm.size(); i++)
	{
		int ans = 0;;
		int sum = 0;

		for (int j = 0; j < pi.size(); j++)
			sum += epi_check_board[i][j];

		// Nếu hàng nào có phần tử epi_check_board[i][k] == 1 thì đẩy nó vào mảng epi ví dụ -0-1
		if (sum == 1)
		{
			for (int k = 0; k < pi.size(); k++)
			{
				if (epi_check_board[i][k] == 1)
				{
					epi.push_back(pi[k]);
					break;
				}
			}
		}
	}

	// Lọc những phần tử dư thừa trong mảng pi và lưu vào mảng nepi
	nepi = duplication(pi, epi);

	// Sắp xếp các tế bào lớn tăng dần. Thay dấu - thành kí tự khác để dùng hàm sort
	for (int i = 0; i < epi.size(); i++)
	{
		for (int j = 0; j < bitnum; j++)
		{
			if (epi[i][j] == '-')
				epi[i][j] = '2';
		}
	}

	for (int i = 0; i < nepi.size(); i++)
	{
		for (int j = 0; j < bitnum; j++)
		{
			if (nepi[i][j] == '-')
				nepi[i][j] = '2';
		}
	}
	sort(epi.begin(), epi.end());
	sort(nepi.begin(), nepi.end());

	// Trả kí tự 2 thành dấu -
	for (int i = 0; i < epi.size(); i++)
	{
		for (int j = 0; j < bitnum; j++)
		{
			if (epi[i][j] == '2')
				epi[i][j] = '-';
		}
	}

	for (int i = 0; i < nepi.size(); i++)
	{
		for (int j = 0; j < bitnum; j++)
		{
			if (nepi[i][j] == '2')
				nepi[i][j] = '-';
		}
	}

	// Lọc trùng và đẩy vào mảng kết quả cuối cùng mảng answer
	epi.erase(unique(epi.begin(), epi.end()), epi.end());
	for (int i = 0; i < epi.size(); i++)
		answer.push_back(epi[i]);

	for (int i = 0; i < nepi.size(); i++)
		answer.push_back(nepi[i]);

	// Xuất kết quả tất cả các tế bào lớn tìm thấy: 
	cout << "All of big cell: ";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	cout << endl;
}

/*
Hàm đếm số lương dấu gạch trong một chuổi truyền vào
*/
inline int countDash(string src) {
	int count = 0;
	for (int i = 0; i < src.length(); i++) {
		if (src[i] == '-') {
			count++;
		}
	}
	return count;
}

/*
Hàm sort mảng tế bào lớn theo số lượng dấu gạch
*/
inline void sortByNumDash(vector <string> &answer) {
	for (int i = 0; i < answer.size() - 1; i++) {
		for (int j = i + 1; j < answer.size(); j++) {
			if (countDash(answer[i]) < countDash(answer[j])) {
				swap(answer[i], answer[j]);
			}
		}
	}
}

/*
Lọc những tế bào nhất thiết phải có trong đống tất cả các tế bào lớn vừa tìm được
Ví dụ: ta có 2 tế bào lớn là 00-- và 0--0 thì sau bước này nó sẽ trỏ thành: 00-- và 01-0
Cụ thể: Ta sẽ tổ hợp tất cả các cặp tế bào lớn lại với nhau và tiến hành phép tính. Sẽ có nhiều trường hợpp xãy ra
nhưng cụ thể ví dụ ở đây c1 = 00--
						 c2 = 0--0 . Ta thấy c1[0] = c2[0] ta ghi lại kí tự 0. Tiếp theo c1[1] = 0, c2[2] = -
ta sẽ ghi (c1[1] + 1) % 2. Còn vài trường hợp tổ hợp như vậy và ta sẽ dựa vào đó để tính toán. 
Ta dùng vòng while duyệt tới khi nào không còn cặp nào có thể ghép lại được với nhau thì thôi.
*/
void McCluskeyAlgorithm::Minimizer()
{
	int count = 1;

	do {
		count++;
		for (int i = 0; i < answer.size() - 1; i++) {
			sortByNumDash(answer);
			for (int j = i + 1; j < answer.size(); j++) {
				string cell = "";

				for (int k = 0; k < this->num_var; k++) {
					if (answer[i].at(k) != answer[j].at(k) && answer[i].at(k) != '-' && answer[j].at(k) != '-') {
						goto a;
					}
				}

				for (int k = 0; k < this->num_var; k++) {
					if (answer[i].at(k) != answer[j].at(k)) {
						if (answer[i].at(k) == '0' && answer[j].at(k) == '-') {
							cell.append("1");
						}
						if (answer[i].at(k) == '1' && answer[j].at(k) == '-') {
							cell.append("0");
						}
						if (answer[i].at(k) == '-') {
							string temp = answer[j].substr(k, 1);
							cell.append(temp);
						}
					}
					else {
						string temp = answer[j].substr(k, 1);
						cell.append(temp);
					}
				}

				if (cell == answer[j]) {
					answer.erase(answer.begin() + j);
					j--;
				}
				else {
					answer[j] = cell;
					i = 0;
				}
			a: {};
			}
		}
	} while (count < 5);

	cout << "Minimizer: ";

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	cout << endl;
}

McCluskeyAlgorithm::~McCluskeyAlgorithm()
{
}

/*
Lấy input từ người dùng
*/
void McCluskeyAlgorithm::Input()
{
	MapGuild m(this->num_var);

	m.set_Map();
	m.show();

	int in;

	cout << "\nInput value followed by ENTER [^D ends input]\n> ";

	while (cin >> in) {
		system("cls");

		m.update(in);
		m.show();

		cout << "\nInput value followed by ENTER [^D ends input]\n ";
		cout << "> ";

		this->input_arr.push_back(in);
	}

	sort(this->input_arr.begin(), this->input_arr.end());
}
