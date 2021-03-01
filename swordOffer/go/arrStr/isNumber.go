package main

type State int

const (
	initialState State = iota
	intSignState
	integerState
	pointState
	pointWithoutIntState
	fractionState
	expState
	expSignState
	expNumberState
	endState
)

type CharType int

const (
	numberChar CharType = iota
	expChar
	pointChar
	signChar
	spaceChar
	illegalChar
)

func toType(b byte) CharType {
	switch b {
	case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
		return numberChar
	case 'e', 'E':
		return expChar
	case '.':
		return pointChar
	case '+', '-':
		return signChar
	case ' ':
		return spaceChar
	default:
		return illegalChar
	}
}

func isNumber(s string) bool {
	transfer := map[State]map[CharType]State{
		initialState: {
			spaceChar:  initialState,
			signChar:   intSignState,
			numberChar: integerState,
			// expChar:    expState, mistake
			pointChar: pointWithoutIntState, // missing
		},
		intSignState: {
			numberChar: integerState,
			pointChar:  pointWithoutIntState, // missing
			// expChar:    expState, mistake
			// spaceChar:  endState, mistake
		},
		integerState: {
			pointChar:  pointState,
			expChar:    expState,
			numberChar: integerState,
			spaceChar:  endState,
		},
		pointState: {
			numberChar: fractionState,
			spaceChar:  endState,
			expChar:    expState, // missing
		},
		pointWithoutIntState: {
			numberChar: fractionState,
			// spaceChar:  endState, mistake
		},
		fractionState: {
			numberChar: fractionState,
			expChar:    expState,
			spaceChar:  endState,
		},
		expState: {
			numberChar: expNumberState,
			signChar:   expSignState,
			// spaceChar:  endState, mistake
		},
		expSignState: {
			numberChar: expNumberState,
			// spaceChar:  endState, mistake
		},
		expNumberState: {
			numberChar: expNumberState,
			spaceChar:  endState,
		},
		// missing. this block is must, tail space can be more than one
		endState: {
			spaceChar: endState,
		},
	}

	state := initialState
	var ok bool

	for i := 0; i < len(s); i++ {
		if state, ok = transfer[state][toType(s[i])]; !ok {
			return false
		}
	}

	return state == endState ||
		state == integerState ||
		state == expNumberState ||
		state == fractionState ||
		state == pointState // 3. is valid
}
