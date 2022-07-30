/* 
    Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
    · MakeRoot u: Tạo ra nút gốc u của cây
    · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
    · CountLeaves u:  đếm và trả ra số nút lá trên cây có gốc là u 
    · CountKChildren u k: đếm và trả về số nút có đúng k nút con trên cây gốc u
    Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
    · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
    · Kết quả: ghi ra mỗi dòng kết quả của các lệnh CountLeaves và CountKChildren tương ứng đọc được từ đầu vào
    
    Ví dụ:
    Dữ liệu
    MakeRoot 10
    Insert 11 10
    Insert 1 10
    Insert 3 10
    Insert 5 11
    Insert 4 11
    CountLeaves 4
    CountKChildren 10 3
    Insert 8 3
    Insert 2 3
    Insert 7 3
    Insert 6 4
    Insert 9 4
    CountKChildren 10 3
    CountLeaves 10
    CountLeaves 3
    *
    Kết quả
    1
    1
    2
    7
    3
*/
//Xem count.c, Week 13 - Đang sai: Sửa đi