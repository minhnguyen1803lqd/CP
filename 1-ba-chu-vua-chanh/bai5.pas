program bai_5;
uses crt;
var a, b, c, d, m, n, p, q: integer;
    lt: array [1..4] of integer;
procedure Nhap(var a, b, c, d, m, n, p, q: integer);
    begin
        write('Nhap cac so a, b, c, d, m, n, p, q: ');
        readln(a, b, c, d, m, n, p, q);
    end;
procedure Luythua(a, b: integer; var kq: integer);
    var tmp, i: integer;
    begin
        tmp   := 1;
        for i := 1 to b do tmp := tmp * a;
        kq    := tmp;
    end;
begin
    clrscr;
    Nhap(a, b, c, d, m, n, p, q);
    
    Luythua(a, m, lt[1]);
    Luythua(b, n, lt[2]);
    Luythua(c, p, lt[3]);
    Luythua(d, q, lt[4]);
    
    writeln('S = ', lt[1] + lt[2] + lt[3] + lt[4]);
    readln;
end.