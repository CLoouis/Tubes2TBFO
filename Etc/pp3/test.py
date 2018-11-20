#
# Unit tests for calculator
#

import unittest
import tokens
import math
import calculator
#import solution as calculator

# --------------------------------------------------------------------

class TestCalculator(unittest.TestCase):

  def check_expr(self, expr, result):
    r = calculator.parse(expr)
    self.assertTrue(abs(r - result) < 1e-13,
                    "Result of %s != %g" % (expr, result))

  def check_error(self, expr, pos, msg):
    try:
      r = calculator.parse(expr)
      self.assertTrue(false, "No error raised in %s" % expr)
    except calculator.InputError as e:
      self.assertEqual(e.msg, msg)
      self.assertEqual(e.token.pos, pos)

  def test_pi(self):
    self.check_expr("pi", math.pi)
    self.check_expr("2 * pi", 2 * math.pi)
    
  def test_e(self):
    self.check_expr("e", math.e)
    self.check_expr("e^2", math.e * math.e)
    self.check_expr("1 - e^-1", 1.0 - 1/math.e)
    
  def test_division(self):
    self.check_error("4.5 / 0", 4, "Division by zero")
    self.check_error("1 + 2 + 3 + 4 / (10 - 2 * 5)", 14, "Division by zero")

  def test_absolute(self):
    self.check_expr("|17|", 17)
    self.check_expr("|-17|", 17)
    self.check_error("|3 + 4 )", 7, "Expected operator or '|'")
    self.check_expr("3 + |7 - 5 * 9|", 3 + abs(7 - 5 * 9))
    self.check_expr("9 - |3 - |9 - 3 * 4||", 9 - abs(3 - abs(9 - 3 * 4)))

# --------------------------------------------------------------------

if __name__ == '__main__':
  unittest.main()

# --------------------------------------------------------------------
