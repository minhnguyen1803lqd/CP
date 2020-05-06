program bai_2;
uses crt;
var a, b, c: integer;

procedure Nhap(var a, b, c: integer);
    begin
        write('nhap 3 so a, b, c: ');
        readln(a, b, c);
    end;

procedure DT(a, b, c: integer);
    var p, s: real;
    begin
        p := (a + b + c) / 2;
        s := sqrt(p * (p - a) * (p - b) * (p - c));
        writeln('dien tich tam giac co do dai 3 canh la ', a, ', ', b, ', ', c, ': ', s:2:2);
    end;
    
procedure Tamgiac(a, b, c: integer);
    begin
        if (a + b > c) and (a + c > b) and (b + c > a) then
            begin
                writeln('bo 3 so ', a, ', ', b, ', ', c, ' tao thanh 3 canh cua mot tam giac');
                DT(a, b, c);
            end
        else writeln('bo 3 so ', a, ', ', b, ', ', c, ' khong tao thanh 3 canh cua mot tam giac');
    end;
    
begin
    clrscr;
    Nhap(a, b, c);
    Tamgiac(a, b, c);
    readln;
end.