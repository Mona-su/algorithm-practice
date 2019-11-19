// 855. Exam Room

// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
// When a student enters the room, they must sit in the seat that maximizes the 
// distance to the closest person.  If there are multiple such seats, they sit 
// in the seat with the lowest number.  (Also, if no one is in the room, then the 
//     student sits at seat number 0.)
// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() 
// returning an int representing what seat the student sat in, and ExamRoom.leave(int p) 
// representing that the student in seat number p now leaves the room.  It is guaranteed 
// that any calls to ExamRoom.leave(p) have a student sitting in seat p.


class ExamRoom {
private:
    set<int> seats;
    int seated;
    int total;
public:
    ExamRoom(int N) {
        total = N;
        seated = 0;
    }
    
    int seat() {
        if (seated >= total)
            return -1;
        if (seated == 0) {
            seats.insert(0);
            seated++;
            return 0;
        }
        int max_space = 0, prev, max_seat;
        auto itr = seats.begin();
        prev = max_seat = *itr;
        max_space = max(prev, max_space);
        max_seat = 0;
        for (itr = seats.begin()++; itr != seats.end(); itr++) {
            if (*itr - prev <= 1) {
                prev = *itr;
                continue;
            }
            else {
                int half = (prev + *itr) / 2;
                if (half - prev > max_space) {
                    max_space = half - prev;
                    max_seat = half;
                }
            }
            prev = *itr;
        }
        if (prev != total - 1) {
            if (total - 1 - prev > max_space) {
                max_seat = total - 1;
                max_space = total - 1 - prev;
            }
        }
        seated++;
        seats.insert(max_seat);
        return max_seat;
    }
    
    void leave(int p) {
        auto itr = seats.find(p);
        seats.erase(itr);
        seated--;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */