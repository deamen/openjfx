/*
 * Copyright (c) 2012, 2014, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */
package com.sun.glass.ui.swt;

import com.sun.glass.ui.Pixels;
import java.nio.ByteBuffer;
import java.nio.IntBuffer;

final class SWTPixels extends Pixels {

    public SWTPixels(int width, int height, ByteBuffer data) {
        super(width, height, data);
    }

    public SWTPixels(int width, int height, IntBuffer data) {
        super(width, height, data);
    }

    protected SWTPixels(int width, int height, IntBuffer data, float scale) {
        super(width, height, data, scale);
    }

    @Override
    protected void _fillDirectByteBuffer(ByteBuffer bb) {
        //TODO - not implemented
    }

    @Override
    protected void _attachInt(long ptr, int w, int h, IntBuffer ints, int[] array, int offset) {
        //TODO - not implemented
    }

    @Override
    protected void _attachByte(long ptr, int w, int h, ByteBuffer bytes, byte[] array, int offset) {
        //TODO - not implemented
    }
}
