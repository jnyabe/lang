g x y = x ^ 2 - y ^ 2 - x + y
main = do
  print "x"
  x <- getLine
  print "y"
  y <- getLine
  print("g(" ++ x ++ "," ++ y ++ ")=" ++ g (read x ::Int) (read y ::Int))
