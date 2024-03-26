1. brew install pipx(pipx는 Python 애플리케이션을 위한 가상 환경을 자동으로 관리해주는 도구)
2. pipx ensurepath
3. pipx completions
4. .zshrc
5. 파일의 끝에 다음 명령어들을 추가
autoload -U bashcompinit
bashcompinit
eval "$(register-python-argcomplete pipx)"
6. pipx install ipykernel
7. /Users/junwlee/Documents/Today-I-Learn/NumPy_Basic/.conda/bin/python -m pip install numpy
