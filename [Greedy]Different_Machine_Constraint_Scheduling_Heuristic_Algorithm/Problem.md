Có n công việc, được phân công cho m máy khác nhau thực hiện đồng thời. Trong số các công việc trên, có những công việc chỉ có thể được thực hiện trên một số máy nhất định. Hãy viết chương trình dùng thuật giải heuristic tìm một phương án phân công sao cho thời gian để các máy hoàn thành hết n công việc là ngắn nhất.

INPUT

Dòng đầu tiên chứa hai số n và m

m dòng tiếp theo, mỗi dòng chứa n số nguyên dương x0, x1, …, xn-1 Trong đó số xi ở dòng thứ j là thời gian cần thiết để máy thứ j hoàn thành công việc i, nếu xi có giá trị nhỏ hơn 0 điều đó có nghĩa máy thứ j không thể thực hiện công việc i

OUTPUT

Xuất trên một dòng n số nguyên dương y0, y1, …,yn-1, giá trị mỗi số trong đoạn [0, m-1] trong đó giá trị của yi là số thứ tự của máy được phân công để thực hiện công việc i.

VÍ DỤ

Input

4 3

Output

684 -1 -1 886

465 686 377 898

565 995 902 -1

1 2 1 0