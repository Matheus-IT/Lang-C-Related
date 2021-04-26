def extractTags(line: str):
	stringAux: str = ''

	isAngleOpen = False
	for ch in line:
		if ch == '\n':
			continue
		if ch == '<':
			isAngleOpen = True
			continue
		if ch == '>':
			isAngleOpen = False
			continue
		if isAngleOpen:
			continue
		else:
			stringAux += ch

	return stringAux


inputFileName = '.\\09Parsing_html\\pag1.html'
outputFileName = '.\\09Parsing_html\\arquivoDeSaida.html'

f1 = open(inputFileName, encoding='utf8')
f2 = open(outputFileName, 'w')

result: str = ''
for line in f1:
	result = extractTags(line)

	if result:
		f2.write(f'{result}\n')


f1.close()
f2.close()
