namespace WinFormsApp9
{
    public partial class Form1 : Form
    {

        public string op;
        public string number;
        public bool number2;
        public Form1()
        {
            number2 = false;
            InitializeComponent();
        }

        private void button21_Click(object sender, EventArgs e)
        {
            if (number2)
            {
                number2 = false;
                textBox1.Text = "0";
            }
            Button A = (Button)sender;
            if (textBox1.Text == "0") textBox1.Text = A.Text;
            else textBox1.Text = textBox1.Text + A.Text;
        }



        private void textBox1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            Button A = (Button)sender;
            op = A.Text;
            number = textBox1.Text;
            number2 = true;
        }

        private void button4_Click(object sender, EventArgs e) 
        {
            string currentText = textBox1.Text;

            if (currentText.Length > 0)
            {
                currentText = currentText.Substring(0, currentText.Length - 1);
                textBox1.Text = currentText;
            }
        }

        private void button24_Click(object sender, EventArgs e)
        {
            double doubleNumber1, doubleNumber2, res = 0.0;
            doubleNumber1 = Convert.ToDouble(number);
            doubleNumber2 = Convert.ToDouble(textBox1.Text);

            if (op == "X") res = doubleNumber1 * doubleNumber2;

            else if (op == "/") 
            {
                if (doubleNumber2 == 0)
                {
                    textBox1.Text = "error";
                    return;
                }
                res = doubleNumber1 / doubleNumber2;
            }

            if (op == "+") res = doubleNumber1 + doubleNumber2;
            else if (op == "-") res = doubleNumber1 - doubleNumber2;
            else if (op == "%") res = doubleNumber1 * doubleNumber2 / 100;
       

            op = "=";
            number2 = true;
            textBox1.Text = res.ToString();
        }


        private void button5_Click(object sender, EventArgs e)
        {
            double num, res;
            num = Convert.ToDouble(textBox1.Text);
            res = Math.Sqrt(num); // надеюсь можно было использовать готовые функции
            textBox1.Text = res.ToString();

        }

        private void button6_Click(object sender, EventArgs e)
        {
            double num, res;
            num = Convert.ToDouble(textBox1.Text);
            res = Math.Pow(num, 2);
            textBox1.Text = res.ToString();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            double num, res;
            num = Convert.ToDouble(textBox1.Text);
            res = 1 / num;
            textBox1.Text = res.ToString();
        }

        private void button22_Click(object sender, EventArgs e)
        {

            double num, res;
            num = Convert.ToDouble(textBox1.Text);
            res = -num;
            textBox1.Text = res.ToString();
        }

        private void button23_Click(object sender, EventArgs e)
        {
            if (!textBox1.Text.Contains(".")) textBox1.Text = textBox1.Text + ".";
        }

    }
}