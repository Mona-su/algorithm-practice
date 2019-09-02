# credit_suisse_enter_problem.py

def main(action_type,input_string):
  if (not isinstance(action_type, int)):
    raise Exception("invalid action type")
  if (action_type != 1 and action_type != 2):
    raise Exception("action out of range")
  
  ans = input_string
  if (action_type == 1):
    for i in range(len(input_string)-1):
      if ((ord(input_string[i+1]) == ord(input_string[i])+32) or (ord(input_string[i+1]) == ord(input_string[i])-32)):
        ans = input_string[:i] + input_string[i+2]
        print("**" + ans)
        i = i+1
  #print(ans)
  return ans
