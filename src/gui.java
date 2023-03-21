import javax.swing.*;

public class gui{
    public static void main(String[] args) {
        JFrame frame = new JFrame("Math Equation Plotter");
        JLabel label = new JLabel("f(x) = ");
        JPanel panel = new JPanel();
        JTextField textField = new JTextField(40);
        JButton submitButton = new JButton("Submit");

        panel.add(label);
        panel.add(textField);
        panel.add(submitButton);
        frame.add(panel);

        frame.pack();
        frame.setVisible(true);
    }
}
