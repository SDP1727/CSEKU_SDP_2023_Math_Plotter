import javax.swing.*;

public class gui extends JFrame {

    public gui() {
        setTitle("My Window");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        gui window = new gui();
    }
}