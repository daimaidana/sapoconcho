#ifndef sapoconcho_h
#define sapoconcho_h

class sapoconcho {
  public:
    sapoconcho();
    void forward(int l, int r, int t);
    void reverse(int l, int r, int t);
    void rotate(int l, int r, int t);
    void brake(int t);
    void drive(int l, int r, int t);
};
#endif
