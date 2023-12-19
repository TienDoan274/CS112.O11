Cài đặt thuật giải A* tìm kiếm đường đi ngắn nhất trên đồ thị.

CÀI ĐẶT THEO MÃ GIẢ BÊN DƯỚI + CÁCH TỔ CHỨC CTDL NHƯ GV HƯỚNG DẪN TẠI LỚP.

CÁCH GIẢI KHÁC (THAM KHẢO TRÊN MẠNG ) LÀ KHÔNG HỢP LỆ, VÌ GV SẼ NGHI NGỜ LÀ ĐẠO CODE

 

INPUT

Dòng đầu tiên chứa hai số nguyên v và e. Đây lần lượt là số đỉnh và số cạnh trên đồ thị.

Dòng thứ hai chứa hai chuỗi s và u, đây là tên đỉnh bắt đầu và đỉnh kết thúc.

Dòng thứ ba chứa v chuỗi cách nhau bởi khoảng trắng, đây là danh sách các đỉnh trên đồ thị.

Dòng thứ 4 chứa v số nguyên dương. Số thứ i trong dòng này cho biết giá trị ước lượng khoảng cách từ đỉnh thứ i trong danh sách đỉnh đến đỉnh kết thúc.

e dòng cuối cùng mỗi dòng chứa hai chuỗi v và w cùng một số nguyên dương x, cho biết có một cạnh với độ dài x đi từ đỉnh v vào đỉnh w

 

OUTPUT

Xuất ra hai dòng:

Dòng thứ nhất xuất ra đường đi từ đỉnh bắt đầu s đến đỉnh kết thúc u tìm được theo thuật giải A*. Mỗi đỉnh trên đường đi cách nhau bởi khoảng trắng, đỉnh s và u được tính trong đường đi. Nếu không có đường đi xuất ra chuỗi -unreachable-

Dòng thứ hai xuất ra số lượng đỉnh đã được phát triển trong quá trình tìm kiếm  (tức đỉnh được mở rộng bằng cách thêm các con của nó vào cây tìm kiếm)  và độ dài đường đi (nếu không có đường đi thì độ dài xem như zero)

 

Thứ tự để xét mở rộng các đỉnh là thứ tự trong danh sách đỉnh ở hàng thứ ba của input.

LƯU Ý:

1. Trong trường hợp ta tìm được một đường đi ngắn hơn đến đỉnh q đã có trong tập close. Theo đúng thuật giải A* ta phải xóa đỉnh trên ra khỏi close và cập nhật lại đường đi đến q CŨNG NHƯ CÁC ĐỈNH KHÁC LIÊN QUAN dến đỉnh q. Tuy nhiên bước tìm các đỉnh liên quan bị ảnh hưởng là tương đối phức tạp khi cài đặt. Vậy nên trong bài tập này sinh viên chỉ cần cập nhật lại đỉnh q là được.

2. Số lượng đỉnh đã được phát triển = số đỉnh đã đi qua và bỏ vào trong tập Close. Những đỉnh nào xóa ra khỏi close thì không tính. (Đáng lẽ phải đếm hết các đỉnh p đã được chọn từ Open và bỏ vào close kể cả những đỉnh đã xóa khỏi close nhưng cô lười sửa lại các test case). 