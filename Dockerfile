FROM rikorose/gcc-cmake:gcc-5

# Copia tudo para o container
COPY . /test-compiler
WORKDIR /test-compiler

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /test-compiler/configure.sh
RUN chmod +x /test-compiler/entrypoint.sh

# Executa a instalação na criação dos containers
RUN /test-compiler/configure.sh

# Script executado no docker run
ENTRYPOINT ["/test-compiler/entrypoint.sh"]