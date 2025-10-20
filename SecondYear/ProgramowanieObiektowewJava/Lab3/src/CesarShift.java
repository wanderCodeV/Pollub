import java.util.Scanner;

public class CesarShift {
    public String readText()
    {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        return text;
    }

    public String shifting(String text)
    {
        String result = "";
        for (int i = 0; i < text.length(); i++)
        {
            char currentChar = text.charAt(i);
            if(currentChar <= 'Z' && currentChar >= 'A')
            {
                char newChar = (char)(currentChar + 3);
                char fixedChar = (char)((newChar - 'A' ) % 26 + 'A');
                result += fixedChar;
            }
            else if(currentChar <= 'z' && currentChar >= 'a')
            {
                char newChar = (char)(currentChar + 3);
                char fixedChar = (char)((newChar - 'a') % 26 + 'a');
                result += fixedChar;
            }
            else
                result += currentChar;
        }
        return result;
    }
    public String unshifting(String text)
    {
        String result = "";
        for (int i = 0; i < text.length(); i++)
        {
            char currentChar = text.charAt(i);
            if(currentChar <= 'Z' && currentChar >= 'A')
            {
                char newChar = (char)(currentChar - 3);
                char fixedChar = (char)((newChar - 'A' ) % 26 + 'A');
                result += fixedChar;
            }
            else if(currentChar <= 'z' && currentChar >= 'a')
            {
                char newChar = (char)(currentChar - 3);
                char fixedChar = (char)((newChar - 'a') % 26 + 'a');
                result += fixedChar;
            }
            else
                result += currentChar;
        }
        return result;
    }
    public boolean isPalindrome(String text)
    {
        String clean = "";
        for (int i = 0; i < text.length(); i++)
        {
            if(Character.isLetter(text.charAt(i)))
                clean += Character.toLowerCase(text.charAt(i));
        }
        for (int i = 0; 2*i < clean.length(); i++)
        {
            char beginChar = clean.charAt(i);
            char endChar = clean.charAt(clean.length() - 1 - i);
            if(beginChar != endChar)
                return false;
        }
        return true;
    }


}
