using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;

class Program
{
    static Stack<string> onp = new Stack<string>();

    static void ComputeONP(string line) {
        List<string> output = new List<string>();
        int len = line.Length, numberFrom=0;
        bool readNumber = false;
        for(int i=0; i<len; i++){
            string sign = line.Substring(i, 1);
            switch(line[i]) {
                case '+':
                case '-':
                    if(readNumber==true){
                        readNumber = false;
                        string nr = line.Substring(numberFrom, i-numberFrom);
                        output.Add(nr);
                    }
                    while(true){
                        if(onp.Count==0) break;
                        string ts = onp.Peek();
                        if(!ts.Equals("(") && !ts.Equals(")")){
                            onp.Pop();
                            output.Add(ts);
                        } else {
                            break;
                        }
                    }
                    onp.Push(sign);
                    break;
                case '*':
                case '/':
                    if(readNumber==true){
                        readNumber = false;
                        string nr = line.Substring(numberFrom, i-numberFrom);
                        output.Add(nr);
                    }
                    while(true){
                        if(onp.Count==0) break;
                        string ts = onp.Peek();
                        if(ts.Equals("/") || ts.Equals("*")){ // || ts.Equals("(") || ts.Equals(")")){
                            onp.Pop();
                            output.Add(ts);
                        } else {
                            break;
                        }
                    }
                    onp.Push(sign);
                    break;
                case '(':
                    onp.Push(sign);
                    break;
                case ')':
                    if(readNumber==true){
                        readNumber = false;
                        string nr = line.Substring(numberFrom, i-numberFrom);
                        output.Add(nr);
                    }
                    while(true){
                        if(onp.Count==0) break;
                        string ts = onp.Peek();
                        if(!ts.Equals("(")) {
                            onp.Pop();
                            output.Add(ts);
                        } else {
                            onp.Pop();
                            break;
                        }
                    }
                    break;
                default:
                    if(readNumber==false){
                        readNumber = true;
                        numberFrom = i;
                    }
                    break;
            }
        }
        if(readNumber==true){
            string last = line.Substring(numberFrom, line.Length-numberFrom);
            output.Add(last);
        }
        while(onp.Count != 0){
            output.Add(onp.Peek());
            onp.Pop();
        }

        // tutaj ewaluacja onp
        Stack<string> evalOnp = new Stack<string>();
        for(int i=0; i<output.Count; i++) {
            if(!output[i].Equals("+") && !output[i].Equals("-") && !output[i].Equals("*") && !output[i].Equals("/")) {
                evalOnp.Push(output[i]);
            } else {
                int first = int.Parse(evalOnp.Pop());
                int second = int.Parse(evalOnp.Pop());
                checked
                {
                    switch(output[i]){
                    case "+":
                        evalOnp.Push((first+second).ToString());
                        break;
                    case "-":
                        evalOnp.Push((second-first).ToString());
                        break;
                    case "*":
                        evalOnp.Push((first*second).ToString());
                        break;
                    case "/":
                        evalOnp.Push((second/first).ToString());
                        break;
                    }
                }
            }
        }
        Console.WriteLine(evalOnp.Peek());
    }

    static void Main(string[] args)
    {
        string line;
        while(true){
            line = Console.ReadLine();
            if(line==null) break;
            string tmpLine = string.Concat(line, "");
            try{
                ComputeONP(tmpLine);
                onp.Clear();
            } catch (Exception) {
                Console.WriteLine("Error");
            }
        }
    }
}
