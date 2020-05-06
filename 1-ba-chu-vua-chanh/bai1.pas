program bai_1;
uses crt;
var a, b, c: integer;

procedure NhapDuLieu();
    begin
        repeat
            write('nhap 3 so a, b, c: ');
            readln(a, b, c);
            if (a = 0) then writeln('Du lieu bi nhap sai! Yeu cau nhap lai');
        until (a <> 0);
    end;

procedure GPTB2(a, b, c: integer);
    var delta, x1, x2, x: real;
    begin
        delta := sqr(b) - 4 * a * c;
        if (delta > 0) then
            begin
                x1 := (-b + sqrt(delta)) / (2 * a);
                x2 := (-b - sqrt(delta)) / (2 * a);
                writeln('Phuong trinh bac 2 ', a, 'x^2 + ', b, 'x + ', c, ' co 2 nghiem la:');
                writeln('x1 = ', x1:2:2);
                writeln('x2 = ', x2:2:2);
            end
        else if (delta = 0) then
            begin
                x := (-b) / (2 * a);
                writeln('Phuong trinh bac 2 ', a, 'x^2 + ', b, 'x + ', c, ' co 1 nghiem duy nhat la:');
                writeln('x = ', x:2:2);
            end
        else writeln('Phuong trinh bac 2 ', a, 'x^2 + ', b, 'x + ', c, ' vo nghiem.');
    end;
    
begin
    clrscr;
    NhapDuLieu();
    GPTB2(a, b, c);
    readln;
end.