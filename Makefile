
GCC = g++ 
RM = rm -rf

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SRCS = main.cpp TrainManager.cpp Pooling.cpp Weights.cpp \
		FConnect.cpp Activation.cpp Convolution.cpp Normalization.cpp

TRGT = $(BINDIR)/CCN_dummy_0.1.1

INCS = -I$(INCDIR) `pkg-config opencv --cflags`

LIBS = `pkg-config opencv --libs`

# --- Below section does not need to be modified, 
#     unless really needed.

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(TRGT)

$(TRGT) : $(OBJS)
	@mkdir -p $(BINDIR)
	$(GCC) $^ $(LIBS) -o $@
	
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(GCC) -c $< $(INCS) -o $@

clean:
	$(RM) $(OBJS) $(TRGT)


# ----
#
#	@auther: Danish
#	@date  : 2017/08/21
