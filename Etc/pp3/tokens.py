#
# Tokenizer
#
# Splits a given string into a sequence of tokens
#

class Token(object):
  def __init__(self, text, pos, type):
    self.pos = pos
    self.type = type
    if type == "number":
      self.value = float(text)
    else:
      self.value = text
               
  def isNumber(self):
    return self.type == "number"

  def isSymbol(self, s):
    return self.type == "symbol" and self.value == s

  def isIdentifier(self):
    return self.type == "identifier"

  def isStop(self):
    return self.type == "stop"

  def __repr__(self):
    return "Token(%s, %d, %s)" % (repr(self.value), self.pos, repr(self.type))

  def __str__(self):
    if self.isNumber():
      return "Number: %g" % self.value
    if self.isIdentifier():
      return "Identifier: %s" % self.value
    if self.isStop():
      return "Stop"
    return "Symbol: %s" % self.value

# --------------------------------------------------------------------

def number(text, pos):
  return Token(text, pos, "number")

def symbol(text, pos):
  return Token(text, pos, "symbol")

def identifier(text, pos):
  return Token(text, pos, "identifier")

def stop(pos):
  return Token("", pos, "stop")

# --------------------------------------------------------------------

def _is_id(ch):
  return ('a' <= ch and ch <= 'z') or ('A' <= ch and ch <= 'Z') or ch == '_'

def _is_id1(ch):
  return _is_id(ch) or ch in "0123456789"

def _is_digit(ch):
  return ch in "0123456789."
    
def _next_token(s, pos):
  while pos < len(s) and s[pos] in " \n\t\r":
    pos += 1
  if pos == len(s):
    return stop(pos), pos
  begin = pos
  ch = s[pos]
  # Case 1: a (variable) name
  if _is_id(ch):
    while pos < len(s) and _is_id1(s[pos]):
      pos += 1
    return identifier(s[begin:pos], begin), pos
  # Case 2: a number
  if _is_digit(ch):
    while pos < len(s) and _is_digit(s[pos]):
      pos += 1
    return number(s[begin:pos], begin), pos
  # Case 3: a single character
  return symbol(s[pos], begin), pos+1

# --------------------------------------------------------------------

def tokenize(s):
  tokens = []
  pos = 0

  while True:
    tok, npos = _next_token(s, pos)
    tokens.append(tok)
    if tok.isStop():
      return tokens
    pos = npos

# --------------------------------------------------------------------

# Test code

if __name__ == "__main__":
  t = tokenize("a2(3+4.5*a99-(91.33)")
  print("\n".join(map(lambda x: str(x), t)))
  while True:
    s = input("> ")
    if s is None or s.strip() == "":
      break
    print("\n".join(map(lambda x: str(x), tokenize(s))))

# --------------------------------------------------------------------
