begin = 1
end = 1000
ret = 0

digit_str = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
ten_digit_str = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

def get_num_str(n):
    n = str(n)
    if len(n) == 4:
        return ['one', 'thousand']
    if len(n) == 3:
        if n[1:] == '00':
            return [digit_str[int(n[0])],  'hundred']
        else:
            return [digit_str[int(n[0])],  'hundred', 'and'] + get_num_str(n[1:])
    if len(n) == 2:
        if int(n) >= 20:
            if n[1] == '0':
                return [ten_digit_str[int(n[0])]]
            else:
                return [ten_digit_str[int(n[0])]] + get_num_str(n[1:])
        else:
            return [digit_str[int(n)]]
    if len(n) == 1:
        return [digit_str[int(n)]]

for i in range(begin, end + 1):
    ret += reduce(lambda x,y: x+y, map(len, get_num_str(i)))

print ret
