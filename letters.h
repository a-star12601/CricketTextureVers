#ifndef LETTERS_H_INCLUDED
#define LETTERS_H_INCLUDED

void renderStrokeFontString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glPushMatrix();
	glTranslatef(x, y,z);
    glScalef(10,10,10);
	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(font, *c);
	}

	glPopMatrix();
}
void A(){
glPushMatrix();
    glPushMatrix();
    glRotatef(15,0,0,1);
    glScalef(0.3,2,1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6,0,0);
    glRotatef(-15,0,0,1);
    glScalef(0.3,2,1);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3,0,0);
    glScalef(0.6,0.3,1);
    glutSolidCube(1);
    glPopMatrix();
glPopMatrix();
}

#endif // LETTERS_H_INCLUDED
