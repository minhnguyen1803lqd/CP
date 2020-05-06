program bai_3;
uses crt;
var a, b, BC, UC:real;

procedure Nhap(var a, b:real);
    begin
        write('Nhap 2 so: ');
        readln(a, b);
        writeln('2 so vua nhap: ', a:0:2, ', ', b:0:2);
    end;

procedure UCLN(a, b:real; var kq: real);
    begin
        if (a = 0) or (b = 0) then 
            begin
                kq := -1;
                writeln('Khong tim duoc UCLN cua 2 so ', a:0:2, ', ',b:0:2);
                exit();
            end;
        repeat
            if (a > b) then a := a - b
            else b := b - a;
        until (a = b);
        kq := a;
    end;
    
procedure BCNN(a, b:real; var kq: real);
    var tmp: real;
    begin
        if (a = 0) or (b = 0) then 
            begin
                kq := -1;
                writeln('Khong tim duoc BCNN cua 2 so ', a:0:2, ', ',b:0:2);
                exit();
            end;
        UCLN(a, b, tmp);
        kq := (a * b) / (tmp);
    end;
    
begin
    clrscr;
    Nhap(a, b);
    if (a = 0) or (b = 0) then
        begin
            writeln('Khong the tinh duoc UCLN va BCNN cua ', a:0:2, ', ', b:0:2);
            readln;
            exit();
        end;
    UCLN(a, b, UC);
    writeln('UCLN cua ', a:0:2, ', ',b:0:2,' la: ',UC:0:2);
    BCNN(a, b, BC);
    writeln('BCNN cua ', a:0:2, ', ',b:0:2,' la: ',BC:0:2);
    writeln('S = ', (a + b + UC + BC):0:2);
    
    readln;
end.