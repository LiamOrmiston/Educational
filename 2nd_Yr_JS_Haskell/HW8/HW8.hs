import System.Random
import System.IO

main =  randomRIO (1, 10) >>= guess

guess :: Int -> IO ()
guess correctNum = do
  putStrLn "Guess a number: "
  input <- readLn :: IO Int
  if input == correctNum then putStrLn "Correct!"
    else do
      if input > correctNum then putStrLn "Too high" >> guess correctNum
        else do putStrLn "Too low" >> guess correctNum                              
