var updateBoard = function(board, click) {
	const [clickR, clickC] = click;
	const traverseAround = ({ currentRow, currentCol, fun }) => {
		for (let row = -1; row <= 1; row++) {
			for (let col = -1; col <= 1; col++) {
				fun(currentRow + row, currentCol + col);
			}
		}
	};
	const getMinesCount = (currentRow, currentCol) => {
		let result = 0;

		function check(row, col) {
			const value = board[row]?.[col];
			if (value == 'M') result += 1;
		}
		traverseAround({ currentRow, currentCol, fun: check });
		return result;
	};
	const dfs = (row = clickR, col = clickC) => {
		const currnet = board[row]?.[col];
		if (currnet !== 'E') return;
		const minesCount = getMinesCount(row, col);
		board[row][col] = minesCount === 0 ? 'B' : `${minesCount}`;
		if (minesCount > 0) return;

		traverseAround({ currentRow: row, currentCol: col, fun: dfs });
	};

	board[clickR][clickC] === 'M'
		? board[clickR][clickC] = 'X'
		: dfs();
	return board;
};