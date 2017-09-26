package appolab3.cmd;

public class subtraction implements Command {
    /**
     * @param a - simple variable of integer type
     * @param b - simple variable of integer type
     * @return Subtraction of A and B
     */
    @Override
    public int compute(int a, int b) {
        return a - b;
    }
}
