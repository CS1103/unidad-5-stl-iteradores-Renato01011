#ifndef CLASS_6_5_PROGRESSION_H
#define CLASS_6_5_PROGRESSION_H
#include <vector>

class Progression {
protected:
    long first;
    bool FirstTime = true;
public:
    Progression(): first{1} {}
    virtual long firstValue() { return first; }
    long getFirst() {return first;}
};

class ArithProgressionIterator {
    long cur;
    long inc;
    friend class ArithProgression;
    explicit ArithProgressionIterator(long cur, long inc): cur{cur}, inc{inc} {}
public:
    long operator*() {return cur;}
    bool operator==(const ArithProgressionIterator& rhs) {return cur == rhs.cur;}
    bool operator!=(const ArithProgressionIterator& rhs) {return cur != rhs.cur;}
    ArithProgressionIterator operator++() {///prefijo, ++x
        cur = cur + inc;
        return *this;
    }
    ArithProgressionIterator operator++(int) {///sufijo x++
        auto it = *this;
        ++*this;
        return it;
    }
};

class ArithProgression: public Progression {
    long inc;
    long start;
    long stop;
public:
    ArithProgression(): Progression(), inc{1} {}
    ArithProgression(long inc, long start, long stop): Progression(), inc{inc}, start{start}, stop{stop} {}

    using iterator = ArithProgressionIterator;
    iterator begin() {return iterator(start, inc);}
    iterator end() {return iterator(stop, inc);}
};

class GenProgressionIterator {
    long cur;
    long base;
    friend class GenProgression;
    explicit GenProgressionIterator(long cur, long base): cur{cur}, base{base} {}
public:
    long operator*() {return cur;}
    bool operator==(const GenProgressionIterator& rhs) {return cur == rhs.cur;}
    bool operator!=(const GenProgressionIterator& rhs) {return cur <= rhs.cur;}
    GenProgressionIterator operator++() {///prefijo, ++x
        cur = cur*base;
        return *this;
    }
    GenProgressionIterator operator++(int) {///sufijo x++
        auto it = *this;
        ++*this;
        return it;
    }
};

class GenProgression: public Progression {
    long base;
    long start;
    long stop;
public:
    GenProgression(): Progression(), base{2} {}
    GenProgression(long base, long start, long stop): base{base}, start{start}, stop{stop} {}

    using iterator = GenProgressionIterator;
    iterator begin() {return iterator(start, base);}
    iterator end() {return iterator(stop, base);}
};

class FibonacciProgressionIterator {
    long cur;
    long prev;
    friend class FibonacciProgression;
    explicit FibonacciProgressionIterator(long cur, long prev): cur{cur}, prev{prev} {}
public:
    long operator*() {return cur;}
    bool operator==(const FibonacciProgressionIterator& rhs) {return cur == rhs.cur;}
    bool operator!=(const FibonacciProgressionIterator& rhs) {return cur <= rhs.cur;}
    FibonacciProgressionIterator operator++() {///prefijo, ++x
        long temp = cur;
        cur = cur+prev;
        prev = temp;
        return *this;
    }
    FibonacciProgressionIterator operator++(int) {///sufijo x++
        auto it = *this;
        ++*this;
        return it;
    }
};

class FibonacciProgression: public Progression {
    long prev;
    long start;
    long stop;
public:
    FibonacciProgression(): prev{0} {}
    FibonacciProgression(long prev, long first, long stop): prev{prev}, stop{stop} {this->first = first;}

    using iterator = FibonacciProgressionIterator;
    iterator begin() {return iterator(start, prev);}
    iterator end() {return iterator(stop, prev);}

};

template <typename T>
std::vector<long> get_series(T p) {

    std::vector <long> Return;
    Return.push_back(p.getFirst());
    for(auto it = p.begin(); it != p.end(); it++)
        Return.push_back(*it);
    return Return;

}

template <typename T>
long calculate_total(T p) {
    long Return = 0;
    Return += p.firstValue();
    for(auto it = p.begin(); it != p.end(); it++)
        Return += *it;
    return Return;
}

#endif //CLASS_6_5_PROGRESSION_H
