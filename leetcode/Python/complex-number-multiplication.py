class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        def real(num):
            idx = num.find('+')
            return int(num[:idx])
        def comp(num):
            idx = num.find('+')
            return int(num[idx+1:-1])
        num_1_real, num_1_comp = real(num1), comp(num1)
        num_2_real, num_2_comp = real(num2), comp(num2)
        num_real = num_1_real*num_2_real-(num_1_comp*num_2_comp)
        num_comp = num_1_real*num_2_comp + num_1_comp*num_2_real
        return '{}+{}i'.format(num_real, num_comp)