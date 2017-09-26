package appolab3.cmd;

public class multiplication implements Command {
    /**
     * @param a - simple variable of integer type
     * @param b - simple variable of integer type
     * @return Multiplication of A and B
     */
    @Override
    public int compute(int a, int b) {
        return a * b;
    }
}
