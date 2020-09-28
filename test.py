from charles import happy

e = happy.Expression()

a = e.twoFace(False)

a.first.perform()

b = e.twoFace(True)
if b.first is None:
    print("b first is None.")

