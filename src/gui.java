import javax.swing.*;

public class gui extends JFrame {

    private JTextField inputField;
    private JButton submitButton;
    public gui() {
        setTitle("My Window");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        //Text Field
        inputField = new JTextField();
        inputField.setBounds(10, 10, 200, 30);
        add(inputField);

        setVisible(true);
    }

    public static void main(String[] args) {
        gui window = new gui();
    }
}