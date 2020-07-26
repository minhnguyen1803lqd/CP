const N:array[8..30] of byte=(5,7,9 ,15,20,30,40,50,40,30,20,15,18,50,50,50,50,50,50,50,50 ,10,50);
      M:array[8..30] of byte=(7,3,50,2 ,30,10,4 ,10,50,40,50,20,10,40,50,50,3 ,20,50,50,50 ,50,10);
      R:array[8..30] of byte=(3,5,10,5 ,4 ,8 ,3 ,7 ,10,10,8 ,4 ,8 ,20,1 ,10,3 ,8 ,99,20,200,20,30);
Var f:text;
    s:string;
    t,i,j:byte;
    k:integer;
    A:array[0..51,0..51] of char;
    ok:array[1..51,1..51] of boolean;
    dau:byte;
procedure BFS(u,v,t:byte);
begin
 if(u=1)or(v=1)or(u=n[t])or(v=m[t]) then dau:=0;
 if(A[u,v]='*') then exit;
 if (ok[u,v]=false) then exit;
 ok[u,v]:=false;
 BFS(u+1,v,t);
 BFS(u-1,v,t);
 BFS(u,v-1,t);
 BFS(u,v+1,t);
end;
Begin
  randomize;
  for t:=8 to 30 do
    begin
      str(t,s);
      if length(s)=1 then s:='0'+s;
      S:='TEST'+s;
      mkdir(s);
      s:=s+'/LAKES.INP';
      assign(f,s);
      rewrite(f);
      write(f,N[t],' ',M[t],' ');
      for i:=0 to N[t]+1 do
        For j:=0 to M[t]+1 do A[i,j]:='*';
      for i:=1 to N[t] do
       for j:=1 to M[t] do
         if random(R[t])=0 then A[i,j]:='.';
      k:=0;
      fillchar(ok,sizeof(ok),true);
      for i:=1 to N[t] do
       for j:=1 to M[t] do
        if (ok[i,j])and(A[i,j]='.') then  begin dau:=1;BFS(i,j,t); k:=k+dau; end;
      writeln(f,random(k));
      for i:=1 to n[t] do
       begin
         for j:=1 to m[t] do write(f,a[i,j]);
         writeln(f);
       end;
      close(f);
    end;
end.
