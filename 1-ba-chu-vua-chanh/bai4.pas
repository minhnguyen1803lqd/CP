program bai_4;
uses crt;
var a, b, c, d, gt_a, gt_b, gt_cd: integer;

procedure Nhap(var a, b, c, d:integer);
    begin
        write('Nhap 4 so a, b, c, d: ');
        readln(a, b, c, d);
    end;

procedure GT(a: integer; var kq: integer);
    var tmp, i: integer;
    begin
        tmp   := 1;
        for i := 1 to a do tmp := tmp * i;
        kq    := tmp;
    end;
    
begin
    clrscr;
    Nhap(a, b, c, d);
    GT(a, gt_a);
    GT(b, gt_b);
    GT(c + d, gt_cd);
    writeln('S = ', gt_a + gt_b + gt_cd);
    readln;
end.