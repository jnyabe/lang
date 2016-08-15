-- 面積を求める関数の定義
function Heron(a, b, c)
   local area, s
   if a+b > c and b+c > a and c+a > b then
      s = (a + b + c) / 2
      area = math.sqrt(s*(s-a)*(s-b)*(s-c))
   else
      area = -1
   end
   return area
end