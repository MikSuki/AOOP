import java.io.*;
import lexer.*;

public
class Main
{
public
    static void main(String[] args) throws IOException
    {

        Lexer lexer = new Lexer();
        try
        {
            while (true)
            {
                Token t = lexer.scan();
                System.out.println(t.toString());
            }
        }
        catch (IOException e)
        {
            System.out.println(e.getMessage());
        }
    }
}
